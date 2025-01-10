#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int MAXN = 1e6 + 7;
const int INF = 1e9;

vector<int> groups(MAXN);
vector<vector<int>> graph(MAXN);
vector<ll> dp(MAXN, 0);

void dfs(int node, int parent) {
    dp[node] = dp[parent] * max(1, (int)graph[node].size() - 1);
    if (dp[node] > INF) dp[node] = 0;

    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, g, k;
    cin >> n >> g >> k;

    for (int i = 1; i <= g; i++) {
        cin >> groups[i];
    }
    sort(groups.begin() + 1, groups.begin() + 1 + g);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (i == 1) {
            graph[a].push_back(0);
            graph[b].push_back(0);
            graph[0].push_back(a);
            graph[0].push_back(b);
        } else {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    dp[0] = 1;
    dfs(0, 0);

    ll result = 0;
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() != 1) continue;

        ll minVal = dp[i] * k;
        ll maxVal = dp[i] * (k + 1) - 1;

        int startIdx = lower_bound(groups.begin() + 1, groups.begin() + 1 + g, minVal) - groups.begin();
        int endIdx = upper_bound(groups.begin() + 1, groups.begin() + 1 + g, maxVal) - groups.begin() - 1;

        result += max(0, endIdx - startIdx + 1);
    }

    result *= k;

    cout << result;

    return 0;
}
