#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 7;
vector<vector<pair<int, int>>> graph(MAXN);
vector<vector<int>> in(MAXN);
vector<long double> dp(MAXN);
vector<int> level(MAXN);
queue<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int e, d, k;
    cin >> e >> d >> k;
    for (int i = 0; i < e; i++) {
        int z;
        cin >> z;
    }

    for (int i = 1; i <= k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        in[b].push_back(a);
        level[a]++;
    }

    int x = e + d;
    dp[x] = 1;
    q.push(x);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : graph[v]) {
            dp[v] += (dp[u.first] / u.second);
        }
        for (int u : in[v]) {
            level[u]--;
            if (level[u] <= 0) {
                q.push(u);
            }
        }
    }

    int res = 0;
    long double maxx = -1;
    for (int i = 1; i <= e; i++) {
        if (dp[i] > maxx) {
            maxx = dp[i];
            res = i;
        }
    }
    cout << res;
}