#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 3 * 1e5 + 7;
vector<int> graph[MAXN];
vector<bool> visited(MAXN);
vector<int> parent(MAXN);
vector<int> sizes(MAXN, 1);
vector<int> goodness(MAXN, 0);

void dfs(int x) {
    visited[x] = true;
    goodness[x] = goodness[x] ? 0 : 1;
    for (auto u : graph[x]) {
        if (!visited[u]) {
            goodness[u] = goodness[u] ? 0 : 1;
            dfs(u);
        }
    }
}

int find(int i) {
    if (parent[i] == i) {
        return i;
    } else {
        int res = find(parent[i]);
        parent[i] = res;
        return res;
    }
}

void unisame(int i, int j) {
    int irep = find(i);
    int jrep = find(j);
    if (irep == jrep) return;
    int isize = sizes[irep];
    int jsize = sizes[jrep];
    if (isize < jsize) {
        if (goodness[i] != goodness[j]) {
            fill(visited.begin(), visited.begin() + isize + 1, false);
            dfs(i);
        }
        parent[irep] = jrep;
        sizes[jrep] += sizes[irep];
    } else {
        if (goodness[i] != goodness[j]) {
            fill(visited.begin(), visited.begin() + jsize + 1, false);
            dfs(j);
        }
        parent[jrep] = irep;
        sizes[irep] += sizes[jrep];
    }
}

void unidif(int i, int j) {
    int irep = find(i);
    int jrep = find(j);
    if (irep == jrep) return;
    int isize = sizes[irep];
    int jsize = sizes[jrep];
    if (isize < jsize) {
        if (goodness[i] == goodness[j]) {
            fill(visited.begin(), visited.begin() + isize + 1, false);
            dfs(i);
        }
        parent[irep] = jrep;
        sizes[jrep] += sizes[irep];
    } else {
        if (goodness[i] == goodness[j]) {
            fill(visited.begin(), visited.begin() + jsize + 1, false);
            dfs(j);
        }
        parent[jrep] = irep;
        sizes[irep] += sizes[jrep];
    }
}

void solve() {
    int c, a, b;
    cin >> c >> a >> b;
    if (c == 1) {
        if (find(a) == find(b) && goodness[a] != goodness[b]) {
            cout << -1 << "\n";
        } else {
            unisame(a, b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    } else if (c == 2) {
        if (find(a) == find(b) && goodness[a] == goodness[b]) {
            cout << -1 << "\n";
        } else {
            unidif(a, b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    } else if (c == 3) {
        if (find(a) == find(b) && goodness[a] == goodness[b])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    } else if (c == 4) {
        if (find(a) == find(b) && goodness[a] != goodness[b])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (m--) {
        solve();
    }
    return 0;
}