#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 5007;
vector<int> graph[MAXN];
vector<int> dist(MAXN, 0);
priority_queue<pair<int, int>> pq;

void bfs() {
    while (!pq.empty()) {
        int x = dist[pq.top().second];
        int v = pq.top().second;
        pq.pop();
        for (auto u : graph[v]) {
            if (dist[u] < x - 1) {
                dist[u] = x - 1;
                pq.push({x - 1, u});
            }
        }
        x--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int j = n + 1;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            int a, b;
            cin >> a >> b;
            pq.push({b, a});
            dist[a] = max(dist[a], b);
        } else {
            bfs();
            int a;
            cin >> a;
            cout << dist[a] << "\n";
        }
    }
}