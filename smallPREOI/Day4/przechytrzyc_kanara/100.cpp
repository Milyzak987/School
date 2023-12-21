#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int MAXN = 507;
constexpr int INF = 1e9 + 7;
vector<vector<int>> grid(507, vector<int>(507, 0));
vector<pair<int, int>> graph[MAXN * MAXN];

int shortestPath(pair<int, int> start, pair<int, int> end) {
    int res = abs(start.first - end.first) + abs(start.second - end.second);
    return res;
}

void gridToGraph(int n, int x) {
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int node = i * n + j;

            for (int k = 0; k < 4; ++k) {
                int newRow = i + directions[k][0];
                int newCol = j + directions[k][1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1) {
                    int adjNode = newRow * n + newCol;
                    if (grid[i][j] > x) {
                        graph[node].push_back({adjNode, 1});
                        graph[adjNode].push_back({node, 1});
                    } else {
                        graph[node].push_back({adjNode, 0});
                        graph[adjNode].push_back({node, 0});
                    }
                }
            }
        }
    }
}

void bfs(int src) {
    vector<int> d(n, INF);
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : graph[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}

bool check(int n, int k) {
    for(int i = 0; i < n * n; i++) graph[i].clear();
    gridToGraph(n, k);
    bfs(0);
    return d[n * n - 1] <= k;
}

int bs(int k, int n) {
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(n, k))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    int n, k;
    cin >> n >> k;

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (shortestPath(start, end) <= k)
        cout << "TRIV";
    else
        cout << 1;

    return 0;
}
