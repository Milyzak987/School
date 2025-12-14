#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

const ll MAXN = 2e5 + 7;
vector<ll> graph[MAXN];
vector<ll> degree(MAXN, 0);
vector<ll> res(MAXN, 1);

void toposort(ll n) {
    queue<ll> ready;
    vector<ll> order;
    for (ll i = 0; i < n; i++) {
        if (degree[i] == 0)
            ready.push(i);
    }

    while (!ready.empty()) {
        ll v = ready.front();
        ready.pop();
        if (!ready.empty() && degree[v] == degree[ready.front()]) {
            res[v] = -1;
            res[ready.front()] = -1;
        }
        order.push_back(v);
        for (auto u : graph[v]) {
            degree[u]--;
            if (degree[u] == 0)
                ready.push(u);
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        degree[b - 1]++;
    }
    toposort(n);
}