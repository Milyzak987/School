#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const int MAXN = 2e3 + 7;
const ll MOD = 1e9 + 7;
const ll P = 31;
bool prime[MAXN];
int divs[MAXN];
ll pref[MAXN];
ll power[MAXN];

void precomputeHash(string s) {
    int n = s.size();
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * P % MOD;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] * P + s[i]) % MOD;
    }
}

ll getHash(int l, int r) {
    return (pref[r] - (pref[l - 1] * power[r - l + 1] % MOD) + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string c, s;
    cin >> c >> s;
    s = "#" + s;

    precomputeHash(s);

    int q;
    cin >> q;

    
}
