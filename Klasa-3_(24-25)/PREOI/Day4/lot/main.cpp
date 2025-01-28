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
ll curHeight = 0;

void bfs(ll x, vector<ll> &dist) {
    queue<ll> q;
    q.push(x);
    dist[x] = 0;
    curHeight = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        curHeight++;
        for (auto u : graph[v]) {
            if (dist[u] > dist[v]) {
                q.push(u);
            }
            if (minHeights[u] > curHeight) {
                dist[u] = min(dist[u], dist[v] + minHeights[u] - curHeight + 1);
                curHeight = minHeights[u];
            } else {
                dist[u] = min(dist[u], dist[v] + 1);
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
    }
    bfs(1, distStart);
    bfs(n, distEnd);

    // for(ll i = 1; i <= n; i++){
    //     cout << distStart[i] << " " << distEnd[i] << "\n";
    // }

    ll res = INF;
    for(ll i = 1; i <= n; i++){
        if(distStart[i] == distEnd[i] || distEnd[i] + 1 == distStart[i] || distEnd[i] - 1 == distStart[i]){
            res = min(res, distStart[i] + distEnd[i]);
        }
    }
    cout << res;
}