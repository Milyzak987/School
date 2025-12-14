#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

struct edge {
    int v;
    int w;
    int uw;
};

const int MAXN = 2e5 + 7;
vector<edge> graph[MAXN];
ll dist[MAXN][2]; 

void dijkstra(int s) {
    for(int i=0; i<MAXN; i++) {
        dist[i][0] = LLONG_MAX;
        dist[i][1] = LLONG_MAX;
    }
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[s][0] = 0;
    pq.push({0, s * 2});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u_encoded = pq.top().second;
        pq.pop();

        int u = u_encoded / 2;
        int state = u_encoded % 2;

        if (d > dist[u][state]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.v;
            int w = edge.w;
            int uw = edge.uw;
            if (dist[u][state] + w < dist[v][state]) {
                dist[v][state] = dist[u][state] + w;
                pq.push({dist[v][state], v * 2 + state});
            }
            if (state == 0) {
                if (dist[u][0] + uw < dist[v][1]) {
                    dist[v][1] = dist[u][0] + uw;
                    pq.push({dist[v][1], v * 2 + 1});
                }
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
        int u, v, w, uw;
        cin >> u >> v >> w >> uw;
        graph[u].push_back({v, w, uw});
        graph[v].push_back({u, w, uw});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);

    ll ans = min(dist[t][0], dist[t][1]);

    if (ans == LLONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}