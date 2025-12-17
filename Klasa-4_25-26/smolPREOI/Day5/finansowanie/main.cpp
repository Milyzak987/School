#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 7;
const int L = 19;

vector<int> graph[MAXN];
int jump[MAXN][L];
int depth[MAXN];

int parent[MAXN];
int rnk[MAXN];
pii diam_end[MAXN];

struct Operation {
    char type;
    int u, v;
};
vector<Operation> ops;

int n, q;

void dfs(int u, int p, int d) {
    depth[u] = d;
    jump[u][0] = p;
    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
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
        int p1 = diam_end[a].first;
        int p2 = diam_end[a].second;
        int p3 = diam_end[b].first;
        int p4 = diam_end[b].second;

        int candidates[4] = {p1, p2, p3, p4};
        int max_d = -1;
        pii best_pair = {p1, p2};

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int d = dist(candidates[i], candidates[j]);
                if (d > max_d) {
                    max_d = d;
                    best_pair = {candidates[i], candidates[j]};
                }
            }
        }

        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;

        diam_end[a] = best_pair;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == 'S') {
            int u, v;
            cin >> u >> v;
            ops.push_back({type, u, v});

            graph[u].push_back(v);
            graph[v].push_back(u);
        } else {
            int v;
            cin >> v;
            ops.push_back({type, v, 0});
        }
    }

    dfs(1, 0, 0);
    jumpPointers();

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rnk[i] = 0;
        diam_end[i] = {i, i};
    }

    for (const auto op : ops) {
        if (op.type == 'S') {
            Union(op.u, op.v);
        } else {
            int root = Find(op.u);

            int d1 = dist(op.u, diam_end[root].first);
            int d2 = dist(op.u, diam_end[root].second);
            cout << max(d1, d2) << "\n";
        }
    }

    return 0;
}
