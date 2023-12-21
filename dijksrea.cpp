#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> pii;

vector<vector<pii>> graph;

int dijkstra(int source, int destination) {
    vector<int> distance(graph.size(), INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (u == destination) return distance[u];

        if (dist_u > distance[u]) continue;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
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
        int u, v, weight;
        cin >> u >> v >> weight;

        // Undirected graph
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int source, destination;
    cin >> source >> destination;

    int shortestPath = dijkstra(source, destination);

    if (shortestPath == -1)
        cout << "-1\n";
    else
        cout << "Shortest Path Length from node " << source << " to node " << destination << ": " << shortestPath << endl;

    return 0;
}
