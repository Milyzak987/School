#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200007;
vector<int> graph[MAXN];
vector<bool> visited(MAXN, false);
vector<int> colors(MAXN);

bool checkColors(int n) {
    for (int i = 1; i <= n; i++)
        if (colors[i] == colors[i + n] && colors[i] != 0) return false;
    return true;
}

void dfs(int v, int x) {
    visited[v] = true;
    colors[v] = x;
    for (auto u : graph[v])
        if (!visited[u]) dfs(u, x);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        visited[i] = 0;
        colors[i] = 0;
    }
    for (auto& arr : graph) arr.clear();

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;

        if (c == 'A') {
            graph[a].push_back(b);
            graph[b].push_back(a);
            graph[a + n].push_back(b + n);
            graph[b + n].push_back(a + n);
        } else {
            graph[a].push_back(b + n);
            graph[b].push_back(a + n);
            graph[a + n].push_back(b);
            graph[b + n].push_back(a);
        }
    }

    for (int i = 2; i <= n; i++)
        if (!visited[i]) dfs(i, i);

    cout << (checkColors(n) ? "TAK\n" : "NIE\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) solve();
    return 0;
}