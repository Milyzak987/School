#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1000002];
vector<int> dist(1000002, -1);

void BFS(int x) {
    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    dist[0] = 0;
    BFS(0);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << "\n";
    }
}