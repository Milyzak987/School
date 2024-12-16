#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 7;
vector<int> graph[MAXN];
vector<int> dist(MAXN);

void bfs(int x) {
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(b);
    }

    dist.assign(n + 1, -1);

    bfs(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dist[i]);
    }

    cout << ans;
}