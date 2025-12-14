#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> graph[1000002];
vector<long long> dist(1000002, -1);

void dijkstra(int s) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[s].size(); i++) {
            int u = graph[s][i].first;
            if (dist[s] + graph[s][i].second < dist[u] || dist[u] == -1) {
                dist[u] = dist[s] + graph[s][i].second;
                pq.push({dist[u], u});
            }
        }
    }
}

void check(int n) {
    long long m = -1;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (min(dist[i], dist[i + n]) != -1 && dist[i] != dist[i + n])
            m = max(m, dist[i] + dist[i + n]);
    for (int i = 1; i <= n; i++)
        if (dist[i] + dist[i + n] == m && min(dist[i], dist[i + n]) != -1 && dist[i] != dist[i + n]) {
            v.push_back(i);
        }
    if (v.empty()) {
        cout << "BRAK";
    } else {
        for (int x : v) {
            cout << x << " ";
        }
        cout << "\n" << dist[v[0]] + dist[v[0] + n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (c % 2 == 0) {
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
            graph[a + n].push_back({b + n, c});
            graph[b + n].push_back({a + n, c});
        } else {
            graph[a].push_back({b + n, c});
            graph[b].push_back({a + n, c});
            graph[a + n].push_back({b, c});
            graph[b + n].push_back({a, c});
        }
    }
    dijkstra(1);
    check(n);
}