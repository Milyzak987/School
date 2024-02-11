#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 7;
vector<int> power_plants(MAXN);
vector<pair<int, int>> graph[MAXN];
vector<int> dist(MAXN, -1);

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 1;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[s].size(); i++) {
            int u = graph[s][i].first;
            if (dist[s] * graph[s][i].second < dist[u] || dist[u] == -1) {
                dist[u] = dist[s] * graph[s][i].second;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int e, d, k;
    cin >> e >> d >> k;
    for (int i = 1; i <= e; i++) {
        cin >> power_plants[i];
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dijkstra(e + d);

    int minx = dist[1];
    int mini = 1;
    for (int i = 1; i <= e; i++) {
        if (dist[i] < minx) {
            minx = dist[i];
            mini = i;
        }
    }
    cout << mini;
    return 0;
}