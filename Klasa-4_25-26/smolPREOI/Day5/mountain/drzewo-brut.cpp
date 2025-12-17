#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 7;
const int MAXN2 = 1e3 + 7;
const int L = 20;

vector<int> graph[MAXN];
int weights[MAXN];
int up[MAXN][L];
int max_path[MAXN][L];
int depth[MAXN];
int n;
vector<bool> visited(MAXN2, false);

void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;

    if (p != -1)
        max_path[u][0] = max(weights[u], weights[p]);
    else
        max_path[u][0] = weights[u];

    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void dfs2(int v, int h) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u] && weights[u] <= h) dfs2(u, h);
    }
}

void jumpPointers() {
    for (int j = 1; j < L; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];

                max_path[i][j] = max(max_path[i][j - 1], max_path[up[i][j - 1]][j - 1]);
            } else {
                up[i][j] = -1;
                max_path[i][j] = max_path[i][j - 1];
            }
        }
    }
}

int maxWeight(int u, int dist) {
    int res = weights[u];
    for (int j = 0; j < L; j++) {
        if ((dist >> j) & 1) {
            res = max(res, max_path[u][j]);
            u = up[u][j];
        }
    }
    return res;
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int j = L - 1; j >= 0; j--) {
        if (up[u][j] != -1 && depth[up[u][j]] >= depth[v]) {
            u = up[u][j];
        }
    }

    if (u == v) return u;

    for (int j = L - 1; j >= 0; j--) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int query(int u, int v) {
    int lca = LCA(u, v);
    int res_u = maxWeight(u, depth[u] - depth[lca]);
    int res_v = maxWeight(v, depth[v] - depth[lca]);
    return max(res_u, res_v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int q;
    cin >> q;

    if (n < MAXN2 && q < MAXN2) {
        while (q--) {
            int u, v, h;
            cin >> u >> v >> h;
            fill(visited.begin(), visited.end(), false);
            dfs2(u, h + weights[u]);
            if (visited[v]) {
                cout << "TAK\n";
            } else {
                cout << "NIE\n";
            }
        }
        return 0;
    }

    dfs(1, -1, 0);
    jumpPointers();
    for (int i = 0; i < q; i++) {
        int u, v, h;
        cin >> u >> v >> h;
        if (query(u, v) - weights[u] <= h) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}
