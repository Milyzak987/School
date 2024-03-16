#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1e6;
const int INF = 1e9;
vector<int> graph[MAXN];
vector<int> capitals(MAXN);
vector<bool> visited(MAXN, false);

void dfs(int v, int j) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            capitals[u] = j;
            dfs(u, j);
        }
    }
}

int bfs(int s, int x) {
    queue<int> q;
    q.push(s);
    vector<int> dist(MAXN, -1);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == x) return dist[v] + 1;
        for (auto u : graph[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
    return -1;
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n + q; i++) {
        capitals[i] = i;
    }
    int j = n + 1;
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            fill(visited.begin(), visited.end(), false);
            graph[j].push_back(capitals[b]);
            graph[j].push_back(capitals[c]);
            graph[capitals[b]].push_back(j);
            graph[capitals[c]].push_back(j);
            capitals[b] = j;
            capitals[c] = j;
            dfs(j, j);
            j++;
        } else {
            cout << bfs(b, c) << "\n";
        }
    }
    cout << -1;
}