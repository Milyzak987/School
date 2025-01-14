#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 7;
const ll MOD = 1e9 + 7;
const ll P = 31;
ll pref[MAXN];
ll power[MAXN];
ll h = 0;
vector<int> ans;

void precomputeHash(string s, string c, int n, int m) {
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * P % MOD;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] * P + s[i]) % MOD;
    }
    for (int i = 1; i <= m; i++) {
        h = (h * P + c[i]) % MOD;
    }
}

ll getHash(int l, int r) { return (pref[r] - (pref[l - 1] * power[r - l + 1] % MOD) + MOD) % MOD; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string c, s;
    cin >> c >> s;
    int n = s.size(), m = c.size();
    c = "#" + c;
    s = "#" + s;

    precomputeHash(s, c, n, m);

    for (int i = 1; i + m - 1 <= n; i++) {
        if (getHash(i, i + m - 1) == h) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
}