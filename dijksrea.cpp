#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;

vector<vector<int>> graph;

int bfs(int source, int destination) {
    vector<int> distance(graph.size(), INF);
    queue<int> q;

    distance[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == destination) return distance[u];

        for (int v : graph[u]) {
            if (distance[v] == INF) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }

    return -1; // If no path found
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    graph.resize(nodes);

    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int source, destination;
    cin >> source >> destination;

    int shortestPath = bfs(source, destination);

    if (shortestPath == -1)
        cout << "-1\n";
    else
        cout << "Shortest Path Length from node " << source << " to node " << destination << ": " << shortestPath << endl;

    return 0;
}
