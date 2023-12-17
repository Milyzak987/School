//60 punktow
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100002;

vector<int> graph[MAXN];
vector<bool> visited(MAXN, false);
int edges = 0;


int dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        edges++;
        if (!visited[u]) {
            dfs(u);
        }
    }
    return edges;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        cout << dfs(i) << "\n";
        fill(visited.begin(), visited.end(), false);
        edges = 0;
    }

    return 0;
}
