#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 2e5 + 7;
pll coords[MAXN];
vector<ll> graph[MAXN];
ll num[MAXN];
bool visited[MAXN];
set<int> unique;
unordered_map<int, int> vmap;

void dfs(ll v, ll x) {
    visited[v] = true;
    for (ll u : graph[v]) {
        if (!visited[u]) {
            num[u] = x;
            dfs(u, x);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;

    for (ll i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        coords[i] = {a, b};
        unique.insert(a);
        unique.insert(b);
    }

    int idx = 0;
    for (int v : unique) {
        vmap[v] = idx++;
    }

    for (const auto x : coords) {
        int u = vmap[x.first];
        int v = vmap[x.second];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll x = 0;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            x++;
            num[i] = x;
            dfs(i, x);
        }
    }

    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (num[a] == num[b]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
}