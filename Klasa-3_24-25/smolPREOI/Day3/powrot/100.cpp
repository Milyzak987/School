#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 7;

vector<ll> graph[MAXN];
bool visited[MAXN];
ll component[MAXN];
vector<pair<ll, ll>> coords(MAXN);
unordered_map<ll, vector<ll>> mapX, mapY;

void dfs(ll v, ll comp_id) {
    visited[v] = true;
    component[v] = comp_id;
    for (ll u : graph[v]) {
        if (!visited[u]) {
            dfs(u, comp_id);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;

    for (ll i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        coords[i] = {x, y};
        mapX[x].push_back(i);
        mapY[y].push_back(i);
    }

    for (const auto &entry : mapX) {
        const vector<ll> &stations = entry.second;
        for (size_t i = 1; i < stations.size(); i++) {
            graph[stations[i - 1]].push_back(stations[i]);
            graph[stations[i]].push_back(stations[i - 1]);
        }
    }

    for (const auto &entry : mapY) {
        const vector<ll> &stations = entry.second;
        for (size_t i = 1; i < stations.size(); i++) {
            graph[stations[i - 1]].push_back(stations[i]);
            graph[stations[i]].push_back(stations[i - 1]);
        }
    }

    ll comp_id = 0;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp_id++;
            dfs(i, comp_id);
        }
    }

    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (component[a] == component[b]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}