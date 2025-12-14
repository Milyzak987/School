#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)4e18;

int n, m;
vector<vector<pair<int,ll>>> adj;

int LOG;
vector<int> depth;
vector<vector<int>> parent;
vector<ll> h;

void dfs(int v, int p) {
    for (auto [to, w] : adj[v]) {
        if (to == p) continue;
        if (parent[0][to] != -1) continue;
        parent[0][to] = v;
        depth[to] = depth[v] + 1;
        h[to] = h[v] + w;
        dfs(to, v);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
        if (diff & (1 << i))
            a = parent[i][a];
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

inline ll tree_dist(int u, int v) {
    int c = lca(u, v);
    return h[u] + h[v] - 2 * h[c];
}

vector<vector<ll>> dist_from;

vector<ll> dijkstra(int src) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;
        for (auto [to, w] : adj[v]) {
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n + 1, {});
    vector<tuple<int,int,ll>> edges;
    for (int i = 0; i < m; i++) {
        int u, v; ll t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
        edges.push_back({u, v, t});
    }

    depth.assign(n + 1, 0);
    h.assign(n + 1, 0);
    parent.assign(1, vector<int>(n + 1, -1));
    parent[0][1] = 0;
    dfs(1, 0);

    LOG = 1;
    while ((1 << LOG) <= n) LOG++;
    parent.resize(LOG, vector<int>(n + 1, -1));
    for (int i = 1; i < LOG; i++) {
        for (int v = 1; v <= n; v++) {
            if (parent[i - 1][v] > 0)
                parent[i][v] = parent[i - 1][ parent[i - 1][v] ];
        }
    }

    vector<int> special;
    {
        set<pair<int,int>> tree_edges;
        for (int v = 1; v <= n; v++) {
            if (parent[0][v] > 0) {
                int p = parent[0][v];
                tree_edges.insert({min(v,p), max(v,p)});
            }
        }
        for (auto [u,v,w] : edges) {
            pair<int,int> e = {min(u,v), max(u,v)};
            if (!tree_edges.count(e)) {
                special.push_back(u);
                special.push_back(v);
            }
        }
        sort(special.begin(), special.end());
        special.erase(unique(special.begin(), special.end()), special.end());
    }

    for (int v : special) {
        dist_from.push_back(dijkstra(v));
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        ll ans = tree_dist(u, v);
        for (auto &dist : dist_from) {
            ans = min(ans, dist[u] + dist[v]);
        }
        cout << ans << '\n';
    }

    return 0;
}