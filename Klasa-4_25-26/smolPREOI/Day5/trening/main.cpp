#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 7;
const int K = 320;
vector<int> graph[MAXN];
vector<pair<int, int>> bestp[MAXN];
int disabled[MAXN];
int dp[MAXN];
int cntq = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int e, s;
        cin >> e >> s;

        graph[s].push_back(e);
    }

    vector<pair<int, int>> candidates;

    vector<int> seen(n + 1, 0);
    int cookie = 0;

    for (int u = 1; u <= n; ++u) {
        candidates.clear();

        candidates.push_back({0, u});

        for (int v : graph[u]) {
            for (const auto& p : bestp[v]) {
                candidates.push_back({p.first + 1, p.second});
            }
        }

        sort(candidates.begin(), candidates.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; });

        cookie++;
        auto& curr = bestp[u];

        int count = 0;
        for (const auto& p : candidates) {
            if (seen[p.second] != cookie) {
                seen[p.second] = cookie;
                curr.push_back(p);
                count++;
                if (count == K) break;
            }
        }
    }

    for (int k = 0; k < q; ++k) {
        int t, x;
        cin >> t >> x;

        cntq++;
        for (int i = 0; i < x; ++i) {
            int c;
            cin >> c;
            disabled[c] = cntq;
        }

        int ans = -1;
        bool found = false;

        for (const auto& p : bestp[t]) {
            if (disabled[p.second] != cntq) {
                ans = p.first;
                found = true;
                break;
            }
        }

        if (found) {
            cout << ans << "\n";
        } else {
            if (bestp[t].size() < K) {
                cout << -1 << "\n";
            }

            else {
                for (int i = 1; i <= t; ++i) dp[i] = -1;

                dp[t] = 0;
                int res = -1;

                if (disabled[t] != cntq) {
                    res = 0;
                }

                for (int u = t; u >= 1; --u) {
                    if (dp[u] == -1) continue;

                    int d = dp[u];

                    for (int v : graph[u]) {
                        if (d + 1 > dp[v]) {
                            dp[v] = d + 1;
                        }
                    }

                    if (disabled[u] != cntq) {
                        if (dp[u] > res) res = dp[u];
                    }
                }
                cout << res << "\n";
            }
        }
    }

    return 0;
}
