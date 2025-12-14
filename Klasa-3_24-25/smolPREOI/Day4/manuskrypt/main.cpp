#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const int MAXN = 5e5 + 7;
const ll MOD = 1e9 + 7;
const ll P = 31;
bool prime[MAXN];
int divs[MAXN];
ll pref[MAXN];
ll power[MAXN];

void precomputeHash(string s, int n) {
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * P % MOD;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] * P + s[i] - 'a') % MOD;
    }
}

void gen(int n) {
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            divs[i] = i;
            for (int j = i * 2; j <= n; j += i) {
                prime[j] = true;
                divs[j] = divs[j] == 0 ? i : divs[j];
            }
        }
    }
}

Pair factor(int x) {
    int p = divs[x], pow = p;
    while (x % (pow * p) == 0) pow *= p;
    return {p, pow};
}

ll getHash(int l, int r) {
    return (pref[r] - (pref[l - 1] * power[r - l + 1] % MOD) + MOD) % MOD;
}

bool isPeriodic(int l, int r, int period) {
    int n = r - l + 1;
    if (period > n) return false;
    return getHash(l, r - period) == getHash(l + period, r);
}

int shortestPeriod(int l, int r) {
    int iloczyn = 1, len = r - l + 1;
    while (len != iloczyn) {
        Pair k = factor(len / iloczyn);
        if (isPeriodic(l, r, len / k.first)) {
            len /= k.first;
            r = len + l - 1;
        } else {
            iloczyn *= k.second;
        }
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    s = "#" + s;

    precomputeHash(s, n);
    gen(n);

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << shortestPeriod(a, b) << "\n";
    }
}
