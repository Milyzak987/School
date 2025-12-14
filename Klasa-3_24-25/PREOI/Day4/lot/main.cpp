#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll MAXN = 2e5 + 7;
const ll INF = 2e9;
ll minHeights[MAXN];
vector<ll> graph[MAXN];
vector<ll> distStart(MAXN, INF);
vector<ll> distEnd(MAXN, INF);

void dijkstra(int s, vector<ll> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (auto p : graph[v]) {
            int u = p;
            int w = max(minHeights[u] - dist[v], 1ll);
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        cin >> minHeights[i];
    }
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if ((a == 1 && b == n) || (a == n && b == 1)) {
            cout << 1;
            return 0;
        }
    }
    dijkstra(1, distStart);
    dijkstra(n, distEnd);

    ll res = INF;
    for (ll i = 1; i <= n; i++) {
        if (distStart[i] == distEnd[i] || distEnd[i] + 1 == distStart[i] ||
            distEnd[i] - 1 == distStart[i]) {
            res = min(res, distStart[i] + distEnd[i]);
        }
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n == 2) {
        cout << 1;
        return 0;
    }
    cout << res;
}