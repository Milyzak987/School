// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef long double ld;
// typedef pair<ll, ll> pii;

// const int R = (1 << 17);
// const int UP = R;
// const int DOWN = 3 * R;
// const int MAXN = DOWN + 2 * R;
// const ll INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000;
// vector<pii> graph[MAXN];
// vector<ll> dist(MAXN);

// void createUp(int start, int end, int v, int w) {
//     start += R - 1;
//     end += R + 1;
//     while (start / 2 != end / 2) {
//         if (start % 2 == 0) {
//             graph[v].push_back({start + 1 + UP, w});
//         }
//         if (end % 2 == 1) {
//             graph[v].push_back({end - 1 + UP, w});
//         }
//         start /= 2;
//         end /= 2;
//     }
// }

// void createDown(int start, int end, int v, int w) {
//     start += R - 1;
//     end += R + 1;
//     while (start / 2 != end / 2) {
//         if (start % 2 == 0) {
//             graph[start + 1 + DOWN].push_back({v, w});
//         }
//         if (end % 2 == 1) {
//             graph[end - 1 + DOWN].push_back({v, w});
//         }
//         start /= 2;
//         end /= 2;
//     }
// }

// void dijkstra(int start) {
//     fill(dist.begin(), dist.end(), INF);
//     priority_queue<pii, vector<pii>, greater<pii>> q;

//     dist[start] = 0;
//     q.push({0, start});

//     while (!q.empty()) {
//         int v = (int)q.top().second;
//         q.pop();

//         for (pii p : graph[v]) {
//             int u = (int)p.first;
//             ll w = p.second;

//             if (dist[u] > dist[v] + w) {
//                 dist[u] = dist[v] + w;
//                 q.push({dist[u], u});
//             }
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, q, s;
//     cin >> n >> q >> s;

//     for (int i = R - 1; i >= 1; i--) {
//         graph[i + UP].push_back({2 * i + UP, 0});
//         graph[i + UP].push_back({2 * i + 1 + UP, 0});

//         graph[2 * i + DOWN].push_back({i + DOWN, 0});
//         graph[2 * i + 1 + DOWN].push_back({i + DOWN, 0});
//     }

//     for (int i = R; i < 2 * R; i++) {
//         graph[i + UP].push_back({i - R + 1, 0});
//         graph[i - R + 1].push_back({i + DOWN, 0});
//     }

//     while (q--) {
//         int t;
//         cin >> t;
//         if (t == 1) {
//             int v, u, w;
//             cin >> v >> u >> w;
//             graph[v].push_back({u, w});
//         } else {
//             int v, l, r, w;
//             cin >> v >> l >> r >> w;
//             l--;
//             r--;

//             if (t == 2) {
//                 createUp(l, r, v, w);
//             } else {
//                 createDown(l, r, v, w);
//             }
//         }
//     }

//     dijkstra(s);

//     for (int i = 1; i <= n; i++) {
//         if (dist[i] == INF) {
//             cout << "-1 ";
//         } else {
//             cout << dist[i] << " ";
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Zrobione";
}