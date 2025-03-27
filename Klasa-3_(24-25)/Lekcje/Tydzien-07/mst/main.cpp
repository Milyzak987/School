#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int v, u, w, idx;
};

const int MAXN = 3e5 + 7;
Edge edges[MAXN];
int parent[MAXN], result[MAXN];

int find(int x) {
    return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    iota(parent, parent + n + 1, 0);

    for (int i = 1; i <= m; i++) {
        cin >> edges[i].v >> edges[i].u >> edges[i].w;
        edges[i].idx = i;
    }

    sort(edges + 1, edges + 1 + m, [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    ll total_weight = 0;
    int edge_count = 0;

    for (int i = 1; i <= m; i++) {
        if (find(edges[i].v) != find(edges[i].u)) {
            unite(edges[i].v, edges[i].u);
            result[edge_count++] = edges[i].idx;
            total_weight += edges[i].w;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (find(i) != find(1)) {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK\n" << total_weight << "\n";
    for (int i = 0; i < edge_count; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
