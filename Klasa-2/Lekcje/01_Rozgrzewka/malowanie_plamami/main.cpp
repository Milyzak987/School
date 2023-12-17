#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100002;

vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int v) {
    int x = 2;
    int i = 0;
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u] && i<x) {
            i++;
            dfs(u);
        }
    }
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
        graph[b].push_back(a);
    }

    dfs(3);

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}
