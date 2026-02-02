#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int to;
    ll cap;
};

int n, m;
vector<ll> h;
vector<vector<Edge>> graph;
bool possible;

ll dfs(int u, int p) {
    ll currSum = h[u];

    for (auto& edge : graph[u]) {
        int v = edge.to;
        ll cap = edge.cap;

        if (v != p) {
            ll childSum = dfs(v, u);

            if (cap < abs(childSum)) {
                possible = false;
            }

            currSum += childSum;
        }
    }

    return currSum;
}

void solve() {
    cin >> n >> m;

    h.assign(n + 1, 0);
    graph.assign(n + 1, vector<Edge>());
    possible = true;

    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    if (n > 0) {
        dfs(1, -1);
    }

    if (possible)
        cout << "TAK\n";
    else
        cout << "NIE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
