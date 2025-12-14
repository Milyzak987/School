#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

vector<int> adj[MAXN];
vector<pair<int, int>> queries;
vector<long long> cost[MAXN];
vector<long long> result;

int parent[MAXN][MAXN];
int depth[MAXN];
long long dist[MAXN];

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    
    for (int i = 20; i >= 0; --i) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = parent[a][i];
        }
    }

    if (a == b) return a;

    for (int i = 20; i >= 0; --i) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    return parent[a][0];
}

void dfs(int v, int p) {
    parent[v][0] = p;
    depth[v] = depth[p] + 1;

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            dist[v] += dist[u];
        }
    }

    for (auto& q : queries) {
        int a = q.first;
        int b = q.second;

        int common = lca(a, b);

        dist[common] -= 2 * dist[v];
        dist[a] += dist[v];
        dist[b] += dist[v];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        cost[i].clear();
        parent[i][0] = 0;
        depth[i] = 0;
        dist[i] = 0;
    }

    for (int i = 1; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        adj[a].push_back(b);
        adj[b].push_back(a);

        cost[i].push_back(c);
        cost[i].push_back(d);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b});
    }

    dfs(1, 0);

    for (int i = 1; i < n; ++i) {
        int common = lca(i, i + 1);
        result.push_back(min(cost[i][0] * dist[i] + cost[i][1] * dist[i + 1],
                             cost[i][1] * dist[i] + cost[i][0] * dist[i + 1]));
    }

    long long answer = 0;
    for (long long res : result) {
        answer += res;
    }

    cout << answer << endl;

    return 0;
}
