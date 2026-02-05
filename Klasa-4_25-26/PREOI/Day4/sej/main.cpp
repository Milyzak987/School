#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
ll N, K;
string T, S;

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

vector<int> pref(const string& P) {
    int m = P.length();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j]) j = pi[j - 1];
        if (P[i] == P[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> T >> S;

    if (N == 1) {
        if (K == 0) {
            cout << (S == T ? 1 : 0);
        } else {
            cout << 0;
        }
        return 0;
    }

    string text = S + S.substr(0, N - 1);
    string pattern = T;

    string com = pattern + "#" + text;
    vector<int> pi = pref(com);

    int cnt = 0;
    bool valid = false;

    for (int i = N + 1; i < com.length(); i++) {
        if (pi[i] == N) {
            cnt++;

            if (i == 2 * N) {
                valid = true;
            }
        }
    }

    ll term1 = power(N - 1, K);
    ll term2 = (K % 2 == 0) ? 1 : MOD - 1;
    ll invN = modInverse(N);
    ll dif = (term1 - term2 + MOD) % MOD;

    dif = (dif * invN) % MOD;
    ll Same_k = (term1 + ((N - 1) * term2) % MOD) % MOD;
    Same_k = (Same_k * invN) % MOD;
    ll ans = 0;

    if (valid) {
        ans = (Same_k + (ll)(cnt - 1) * dif) % MOD;
    } else {
        ans = ((ll)cnt * dif) % MOD;
    }

    cout << ans;
}