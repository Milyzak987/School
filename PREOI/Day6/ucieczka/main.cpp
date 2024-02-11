#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 7;
vector<int> health(MAXN);
vector<int> last(MAXN, 1);
vector<int> graph[MAXN];
vector<bool> visited(MAXN, false);
int hp = 0, cnt = 0, w;

void dfs(int x) {
    visited[x] = true;
    hp += health[x];
    if (hp < 0) {
        cout << "NIE";
        return;
    } else if (x == w) {
        cout << "TAK";
        return;
    }
    for (auto u : graph[x]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        cin >> health[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    return 0;
}
