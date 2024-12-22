#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 2e5 + 7;
pll coords[MAXN];
vector<ll> graph[MAXN];
ll num[MAXN];
bool visited[MAXN];

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
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i != j) {
                if (coords[i].first == coords[j].first || coords[i].second == coords[j].second) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
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