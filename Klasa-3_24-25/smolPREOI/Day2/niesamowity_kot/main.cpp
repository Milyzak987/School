#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 1;
vector<ll> graph[MAXN];
vector<bool> visited(MAXN);
vector<bool> con(MAXN);
ll n, k, count;

ll dfs(ll v, ll t) {
    visited[v] = true;
    ll x = 0;
    for (auto u : graph[v]) {
        if (!visited[u]) {
            x = max(x, dfs(u, t));
        }
    }
    if (x + 1 >= t && !con[v]) {
        count++;
        x = -1;
    }
    return x + 1;
}

bool canAchive(ll t) {
    count = 0;
    visited.assign(n + 1, false);
    dfs(1, t);
    return count <= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if (a == 1 || b == 1) {
            con[a] = true;
            con[b] = true;
        }
    }

    ll left = 1, right = n - 1, res = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canAchive(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res;
}