#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 7;
const int L = 19;

int h[MAXN];
int parent[MAXN];
vector<pii> graph[MAXN];
int jump[MAXN][L];
int maxe[MAXN][L];
int depth[MAXN];
int comp[MAXN];

struct Edge {
    int u, v;
    int weight;

    bool operator<(const Edge& other) const { return weight < other.weight; }
};

int Find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[b] = a;
}

void dfs(int u, int p, int w, int d, int c_id) {
    depth[u] = d;
    comp[u] = c_id;
    jump[u][0] = p;
    maxe[u][0] = w;

    for (int i = 1; i < L; i++) {
        int p = jump[u][i - 1];
        jump[u][i] = jump[p][i - 1];

        maxe[u][i] = max(maxe[u][i - 1], maxe[p][i - 1]);
    }

    for (auto& edge : graph[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (v != p) {
            dfs(v, u, weight, d + 1, c_id);
        }
    }
}

int maxPath(int u, int v) {
    if (u == v) return 0;

    int res = 0;

    if (depth[u] < depth[v]) swap(u, v);

    for (int i = L - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            res = max(res, maxe[u][i]);
            u = jump[u][i];
        }
    }

    if (u == v) return res;

    for (int i = L - 1; i >= 0; i--) {
        if (jump[u][i] != jump[v][i]) {
            res = max(res, maxe[u][i]);
            res = max(res, maxe[v][i]);
            u = jump[u][i];
            v = jump[v][i];
        }
    }

    res = max(res, maxe[u][0]);
    res = max(res, maxe[v][0]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        parent[i] = i;
    }

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        int w = max(h[u], h[v]);
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    for (const auto& edge : edges) {
        if (Find(edge.u) != Find(edge.v)) {
            Union(edge.u, edge.v);
            graph[edge.u].push_back({edge.v, edge.weight});
            graph[edge.v].push_back({edge.u, edge.weight});
        }
    }

    int comp_count = 0;
    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            comp_count++;
            dfs(i, i, 0, 0, comp_count);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (comp[a] != comp[b]) {
            cout << "NIE\n";
        } else {
            long long limit = c + h[a];
            int g;

            if (a == b) {
                g = h[a];
            } else {
                g = maxPath(a, b);
            }

            if (g <= limit) {
                cout << "TAK\n";
            } else {
                cout << "NIE\n";
            }
        }
    }

    return 0;
}