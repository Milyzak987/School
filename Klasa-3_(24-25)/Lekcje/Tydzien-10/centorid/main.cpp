#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;
vector<int> graph[MAXN];
vector<int> tree[MAXN];
vector<int> sons(MAXN);

void graphToTree(int v, int p) {
    for (auto u : graph[v]) {
        if (u == p)
            continue;
        tree[v].push_back(u);
        graphToTree(u, v);
    }
}

void sonSize(int v) {
    sons[v] = 1;
    for (auto u : tree[v]) {
        sonSize(u);
        sons[v] += sons[u];
    }
}

int centroid(int v, int n) {
    for (auto u : tree[v]) {
        if (sons[u] * 2 > n) {
            return centroid(u, n);
        }
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    graphToTree(1, -1);
    sonSize(1);

    cout << centroid(1, sons[1]);
}
