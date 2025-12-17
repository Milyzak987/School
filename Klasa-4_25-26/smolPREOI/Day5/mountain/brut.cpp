#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e3 + 7;
const int L = 20;

vector<int> graph[MAXN];
vector<int> weights(MAXN);
vector<bool> visited(MAXN, false);

void dfs(int v, int h) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u] && weights[u] <= h) dfs(u, h);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v, h;
        cin >> u >> v >> h;
        fill(visited.begin(), visited.end(), false);
        dfs(u, h + weights[u]);
        if (visited[v]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}
