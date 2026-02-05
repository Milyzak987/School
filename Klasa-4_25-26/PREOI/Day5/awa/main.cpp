#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 6e5 + 7;

ll fact[MAXN];
ll invFact[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) { return power(n, MOD - 2); }

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

ll ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int n, r;
    if (cin >> n >> r) {
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
        }

        int q;
        cin >> q;

        cout << ncr(n + r - 1, r);
    }
}