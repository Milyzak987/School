#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 200000;
vector<int> graph[MAX_N + 1];
int in_degree[MAX_N + 1];
int result[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
        in_degree[x]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int match_count = 0;
    int rank = n;
    while (!q.empty()) {
        match_count++;
        int size = q.size();
        
        vector<int> current_nodes;
        for (int i = 0; i < size; i++) {
            int node = q.front();
            q.pop();
            current_nodes.push_back(node);
        }
        
        for (int node : current_nodes) {
            result[node] = match_count;
            for (int neighbor : graph[node]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] > 0) {
            result[i] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}