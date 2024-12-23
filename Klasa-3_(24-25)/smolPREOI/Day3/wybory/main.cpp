#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const int MAXN = 2e5 + 7;
vector<Pair> graph[MAXN];
ll dist[MAXN][2];
ll distS[MAXN];
ll distT[MAXN];

void dijkstra(ll s, ll j) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    dist[s][j] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        ll v = pq.top().second;
        pq.pop();
        for (auto p : graph[v]) {
            ll u = p.first;
            ll w = p.second;
            if (dist[u][j] > dist[v][j] + w) {
                dist[u][j] = dist[v][j] + w;
                pq.push({dist[u][j], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, t, c, k;
    cin >> n >> m >> s >> t >> c >> k;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    for (int i = 1; i <= n; i++) {
        dist[i][0] = LLONG_MAX;
        dist[i][1] = LLONG_MAX;
    }

    dijkstra(s, 0);
    dijkstra(t, 1);

    if (dist[t][0] <= k) {
        cout << (n * (n - 1)) / 2;
        return 0;
    }
    if (c == k) {
        cout << 1;
        return 0;
    }
    if (c > k) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        distS[i] = dist[i][0];
        distT[i] = dist[i][1];
    }

    sort(distS + 1, distS + 1 + n);
    sort(distT + 1, distT + 1 + n);

    ll res = 0, j = n;
    for (int i = 1; i <= n; i++) {
        while (j > 0 && distS[i] + distT[j] > k - c) {
            j--;
        }
        res += j;
    }

    cout << res;
    return 0;
}