#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;
vector<int> graph[MAXN];
int dist[MAXN];

void bfs(int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

bool canAchieve(int D, int n, int k) {
    vector<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > D) {
            leaves.push_back(i);
        }
    }

    int mods = 0;
    for (int i = 0; i < leaves.size() && mods < k; i++) {
        int x = leaves[i];
        // Dodajemy krawędź do wierzchołka 1
        graph[1].push_back(x);
        graph[x].push_back(1);
        dist[x] = 1;  // Odległość do 1 to teraz 1

        // Zaktualizuj BFS tylko dla wierzchołka 1
        bfs(n);
        mods++;
    }

    // Sprawdzenie, czy udało się osiągnąć odległość <= D
    for (int i = 1; i <= n; i++) {
        if (dist[i] > D) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Początkowe obliczenie odległości
    bfs(n);

    int left = 0, right = n, result = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canAchieve(mid, n, k)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
