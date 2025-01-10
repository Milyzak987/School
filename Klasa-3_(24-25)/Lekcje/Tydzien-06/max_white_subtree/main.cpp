#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int MAXN = 2e5 + 7;

vector<vector<int>> graph(MAXN);
vector<int> values(MAXN), dp(MAXN), result(MAXN);

void dfs1(int node, int parent) {
    dp[node] = values[node];
    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        dfs1(neighbor, node);
        dp[node] += max(0, dp[neighbor]);
    }
}

void dfs2(int node, int parent) {
    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;

        dp[node] -= max(0, dp[neighbor]);
        dp[neighbor] += max(0, dp[node]);

        result[neighbor] = dp[neighbor];

        dfs2(neighbor, node);

        dp[neighbor] -= max(0, dp[node]);
        dp[node] += max(0, dp[neighbor]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        values[i] = (value == 1 ? 1 : -1);
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs1(1, 1);
    result[1] = dp[1];
    dfs2(1, 1);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}
