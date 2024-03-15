#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct spots {
    int v, d, c;
};

const int MAXN = 1e5 + 7;
vector<vector<int>> graph(MAXN);
vector<int> colors(MAXN);
vector<int> v(MAXN, -1);
stack<spots> s;
queue<pair<int, int>> q;

void paint_bfs(int s, int num, int color) {
    q.push({s, num});
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (p.second <= v[p.first]) continue;
        if (colors[p.first] == 0) colors[p.first] = color;
        if (p.second == 0) continue;
        v[p.first] = p.second;
        for (int u : graph[p.first]) {
            if (v[u] >= p.second - 1) continue;
            q.push({u, p.second - 1});
        }
    }
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

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        spots t;
        cin >> t.v >> t.d >> t.c;
        s.push(t);
    }

    while (!s.empty()) {
        paint_bfs(s.top().v, s.top().d, s.top().c);
        s.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << "\n";
    }
}