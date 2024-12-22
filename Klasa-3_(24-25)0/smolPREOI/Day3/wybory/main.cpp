#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 7;
const int INF = 1e9;
vector<pll> graph[MAXN];
vector<pll> graph2[MAXN];
int dist[MAXN];


void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (auto p : graph2[v]) {
            int u = p.first;
            int w = p.second;
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

    int n, m, s, t, c, k;
    cin >> n >> m;
    cin >> s >> t >> c >> k;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(i != j){
                graph[i].push_back({j, c});
                graph[j].push_back({i, c});
                for(int k = 0; k < MAXN; k++){
                    dist[i] = INF;
                }
                dijkstra(s);
                if(dist[t] <= k){
                    res++;
                }
            }
        }
    }

    cout << res;
}