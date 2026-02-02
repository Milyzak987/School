#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 7;
const int L = 19;

vector<int> graph[MAXN];
int sub_sz[MAXN];
int depth[MAXN];
int jump[MAXN][L];
int n;

struct Edge {
    int u, v;
};

vector<Edge> v[MAXN];
int parent[MAXN];
pii diam_end[MAXN];
int maxD = 0;
int ans[MAXN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    jump[u][0] = p;
    sub_sz[u] = 1;

    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            sub_sz[u] += sub_sz[v];
        }
    }
}

void jumpPointers() {
    for (int j = 1; j < L; j++) {
        for (int i = 1; i <= n; i++) {
            if (jump[i][j - 1] != 0)
                jump[i][j] = jump[jump[i][j - 1]][j - 1];
            else
                jump[i][j] = 0;
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int j = L - 1; j >= 0; j--) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = jump[u][j];
        }
    }

    if (u == v) return u;

    for (int j = L - 1; j >= 0; j--) {
        if (jump[u][j] != jump[v][j]) {
            u = jump[u][j];
            v = jump[v][j];
        }
    }
    return jump[u][0];
}

int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[LCA(u, v)]; }

int Find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b) {
        int u1 = diam_end[a].first;
        int v1 = diam_end[a].second;
        int u2 = diam_end[b].first;
        int v2 = diam_end[b].second;

        int best_dist = dist(u1, v1);
        pii best_pair = {u1, v1};

        int d2 = dist(u2, v2);
        if (d2 > best_dist) {
            best_dist = d2;
            best_pair = {u2, v2};
        }

        int candidates[4][2] = {{u1, u2}, {u1, v2}, {v1, u2}, {v1, v2}};

        for (auto& p : candidates) {
            int d = dist(p[0], p[1]);
            if (d > best_dist) {
                best_dist = d;
                best_pair = {p[0], p[1]};
            }
        }

        parent[b] = a;
        diam_end[a] = best_pair;

        if (best_dist > maxD) {
            maxD = best_dist;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) ans[i] = 1;

    dfs(1, 0, 0);
    jumpPointers();

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        diam_end[i] = {i, i};
    }

    for (int u = 2; u <= n; u++) {
        int sz = sub_sz[u];
        int cap = min(sz, n - sz);
        v[cap].push_back({u, jump[u][0]});
    }

    for (int i = n / 2; i >= 1; i--) {
        for (const auto& edge : v[i]) {
            Union(edge.u, edge.v);
        }

        ans[2 * i] = maxD + 1;
    }

    for (int k = 1; k <= n; k++) {
        cout << ans[k] << "\n";
    }

    return 0;
}