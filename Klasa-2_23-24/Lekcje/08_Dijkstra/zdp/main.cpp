#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[500002];
vector<long long> dist(500002, -1);

void dijkstra(int s) {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[s].size(); i++) {
            int u = graph[s][i].first;
            if (dist[s] + graph[s][i].second < dist[u] || dist[u] == -1) {
                dist[u] = dist[s] + graph[s][i].second;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1].push_back(make_pair((b - 1), c));
        graph[b - 1].push_back(make_pair((a - 1), c));
    }

    dijkstra(0);
    for (int i = 0; i < n; i++) cout << dist[i] << "\n";
}