#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 7;
vector<int> graph[MAXN];
vector<bool> visited(MAXN);
int count;

void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            count++;
            dfs(u);
        }
    }
}

long long combination(int n, int k) {
    if (k > n)
        return 0;
    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res * 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count = 0;
            dfs(i);
            res += combination(count + 1, 3);
        }
    }

    cout << res;
}