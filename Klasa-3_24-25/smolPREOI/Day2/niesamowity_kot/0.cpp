#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 2e5 + 7;
vector<ll> graph[MAXN];
ll dist[MAXN];
ll parent[MAXN];
priority_queue<pll> diss;

void bfs(ll x) {
    queue<ll> q;
    q.push(x);
    dist[x] = 0;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (auto u : graph[v])
            if (dist[u] == -1) {
                parent[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    for (ll i = 1; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(b);
    }

    for (ll i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    bfs(1);

    for (ll i = 1; i <= n; i++) {
        diss.push({dist[i], i});
    }


    for (ll i = 0; i < k; i++) {
        while(dist[diss.top().second] != diss.top().first){
            ll t = diss.top().second;
            diss.pop();
            diss.push({dist[t], t});
        }
        ll u = diss.top().second;
        ll x = dist[diss.top().second] / 2;
        while(x != 0) {
            dist[u] = x;
            x--;
            u = parent[u];
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans;
}