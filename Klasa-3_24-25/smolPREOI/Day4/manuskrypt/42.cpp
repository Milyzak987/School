#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 7;
const ll MOD = 1e9 + 7;
const ll P = 31;

vector<ll> power(MAXN), hashPrefix(MAXN);

void precomputeHash(const string &s) {
    int n = s.size();
    power[0] = 1;
    for (int i = 1; i <= n; i++)
        power[i] = (power[i - 1] * P) % MOD;

    for (int i = 1; i <= n; i++)
        hashPrefix[i] = (hashPrefix[i - 1] * P + (s[i - 1] - 'a' + 1)) % MOD;
}

ll getHash(int l, int r) {
    ll hashValue = hashPrefix[r + 1] - (hashPrefix[l] * power[r - l + 1] % MOD);
    if (hashValue < 0)
        hashValue += MOD;
    return hashValue;
}

bool isPeriodic(int l, int r, int period) {
    int len = r - l + 1;
    for (int i = l + period; i <= r; i += period) {
        if (getHash(l, l + period - 1) != getHash(i, i + period - 1)) {
            return false;
        }
    }
    return true;
}

int shortestPeriod(int l, int r) {
    int len = r - l + 1;
    for (int k = 1; k <= len; k++) {
        if (len % k == 0 && isPeriodic(l, r, k)) {
            return k;
        }
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n;

    string s;
    cin >> s;

    precomputeHash(s);

    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << shortestPeriod(l, r) << "\n";
    }
}