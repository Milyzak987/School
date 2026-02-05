#include <bits/stdc++.h>

#include "caplib.h"
using namespace std;
typedef long long ll;

static const int MAXN = 5007;
static vector<int> graph[MAXN];
static int parent[MAXN];
static bool active[MAXN];
static int sz[MAXN];

void dfs1(int u, int p) {
    parent[u] = p;
    for (int v : graph[u]) {
        if (v != p) dfs1(v, u);
    }
}

void dfs2(int u, int p, const vector<int>& nodes) {
    sz[u] = 1;
    for (int v : graph[u]) {
        if (v != p && active[v]) {
            dfs2(v, u, nodes);
            sz[u] += sz[v];
        }
    }
}

int centroid(int u, int p, int t) {
    for (int v : graph[u]) {
        if (v != p && active[v] && sz[v] > t / 2) {
            return centroid(v, u, t);
        }
    }
    return u;
}

int znajdz_capka(int n, vector<pair<int, int>> gal) {
    for (int i = 1; i <= n; ++i) {
        graph[i].clear();
        active[i] = true;
    }

    for (auto& edge : gal) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    dfs1(1, 0);

    int cur = 1;

    while (true) {
        vector<int> nodes;
        for (int i = 1; i <= n; ++i)
            if (active[i]) nodes.push_back(i);

        if (nodes.size() == 1) return nodes[0];

        dfs2(nodes[0], 0, nodes);
        int cen = centroid(nodes[0], 0, nodes.size());

        if (zapytaj(cen)) {
            vector<bool> in_subtree(n + 1, false);
            vector<int> q = {cen};
            in_subtree[cen] = true;
            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                for (int v : graph[u]) {
                    if (v != parent[u]) {
                        in_subtree[v] = true;
                        q.push_back(v);
                    }
                }
            }
            for (int i = 1; i <= n; ++i)
                if (!in_subtree[i]) active[i] = false;
        } else {
            vector<int> q = {cen};
            active[cen] = false;
            int head = 0;
            while (head < q.size()) {
                int u = q[head++];
                for (int v : graph[u]) {
                    if (v != parent[u] && active[v]) {
                        active[v] = false;
                        q.push_back(v);
                    }
                }
            }

            vector<bool> nxt(n + 1, false);
            for (int i = 1; i <= n; ++i) {
                if (active[i]) {
                    if (i == 1)
                        nxt[1] = true;
                    else
                        nxt[parent[i]] = true;
                }
            }
            for (int i = 1; i <= n; ++i) active[i] = nxt[i];
        }
    }
}