#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

const int MAXN = 5e5 + 7;
vector<int> children[MAXN];
vector<int> sz(MAXN, 1);
vector<ld> dp(MAXN, 0.0);
const ld EPS = 1e-11L;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }

    ld ans = 0.0;

    for (int i = n; i >= 1; --i) {
        for (int ch : children[i]) {
            sz[i] += sz[ch];
        }

        if (sz[i] == 1) continue;

        ld denom = (ld)(sz[i] - 1);

        ld trig = 1.0 / denom;

        for (int ch : children[i]) {
            ld cval = min(dp[ch], (ld)sz[ch] / denom);
            trig = max(trig, cval);
        }

        dp[i] = trig;

        if (sz[i] > k) {
            ans = max(ans, dp[i]);
        }
    }

    if(ans >= 1.0L - EPS) ans = 0.0L;

    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}
