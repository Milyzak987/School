#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 7;
vector<int> power_plants(MAXN);
vector<pair<int, int>> graph[MAXN];
vector<bool> visited(MAXN, false);
vector<int> cnts(MAXN, 0);

void dfs(int x, int cnt) {
    visited[x] = true;
    cnt *= graph[x][0].second;
    for (auto u : graph[x]) {
        if (!visited[u.first]) dfs(u.first, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int e, d, k;
    cin >> e >> d >> k;
    for (int i = 1; i <= e; i++) {
        cin >> power_plants[i];
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    if (d == 1) {
        int maxi, minx = 1e9 + 7;;
        for (int i = 1; i <= e; i++) {
            if (graph[i][0].second < minx) {
                minx = graph[i][0].second;
                maxi = i;
            }
        }
        cout << maxi;
    } else {
        int mincount = 1e9 + 7;
        for (int i = 1; i <= e; i++) {
            int cnt = 1;
            dfs(i, cnt);
            cnts[i] = cnt;
        }
        int maxi, minx = 1e9 + 7;;
        for (int i = 1; i <= e; i++) {
            if (cnts[i] < minx) {
                minx = cnts[i];
                maxi = i;
            }
        }
        cout << maxi;
    }
}