#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1007];
vector<bool> visited(1007);

void dfs(int x) {
    visited[x] = 1;
    for (auto u : graph[x]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    vector<pair<int, int>> v(1007);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double dis = sqrt(pow(abs(v[i].first - v[j].first), 2) + pow(abs(v[i].second - v[j].second), 2));
                if (dis <= s) graph[i].push_back(j);
            }
        }

    dfs(0);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) res++;
    }
    cout << res;
}