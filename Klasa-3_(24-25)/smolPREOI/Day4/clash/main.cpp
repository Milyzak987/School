#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Edge {
    int x1, y1, x2, y2, weight;
};

const int MAXN = 1007;
const int MAXNN = MAXN * MAXN;
vector<int> parent(MAXNN);
vector<Edge> edges(2 * MAXNN);
vector<vector<bool>> horizontal(MAXN, vector<bool>(MAXN));
vector<vector<bool>> vertical(MAXN, vector<bool>(MAXN));

int Find(int x) { return parent[x] == x ? x : (parent[x] = Find(parent[x])); }

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        parent[a] = b;
}

int getIndex(int x, int y) { return (y - 1) * 1000 + x; }

void initialize() {
    for (int i = 1; i <= MAXNN; i++) {
        parent[i] = i;
    }
}

void readEdges(int &edgeCount, int &titanEdges, int &chromeEdges, int n, int m) {
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x < m; x++) {
            char c;
            cin >> c;
            edges[++edgeCount] = {x, y, x + 1, y, c == 'T' ? 1 : 2};
            (c == 'T' ? titanEdges : chromeEdges)++;
        }
    }

    for (int y = 1; y < n; y++) {
        for (int x = 1; x <= m; x++) {
            char c;
            cin >> c;
            edges[++edgeCount] = {x, y, x, y + 1, c == 'T' ? 1 : 2};
            (c == 'T' ? titanEdges : chromeEdges)++;
        }
    }
}

void processEdges(int edgeCount, int &removedChrome, int &removedTitan) {
    sort(edges.begin() + 1, edges.begin() + 1 + edgeCount,
         [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

    for (int i = 1; i <= edgeCount; i++) {
        const auto &e = edges[i];
        if (Find(getIndex(e.x1, e.y1)) != Find(getIndex(e.x2, e.y2))) {
            Union(getIndex(e.x1, e.y1), getIndex(e.x2, e.y2));

            if (e.x1 == e.x2) {
                vertical[e.x1][e.y1] = true;
            } else {
                horizontal[e.x1][e.y1] = true;
            }

            if (e.weight == 1)
                removedTitan++;
            else
                removedChrome++;
        }
    }
}

void printResults(int totalEdges, int removedChrome, int removedTitan, int chromeEdges,
                  int titanEdges, int n, int m) {
    cout << (titanEdges + chromeEdges - removedTitan - removedChrome) << " "
         << (chromeEdges - removedChrome) << "\n";

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x < m; x++) {
            cout << (horizontal[x][y] ? '.' : 'Z');
        }
        cout << "\n";
    }

    for (int y = 1; y < n; y++) {
        for (int x = 1; x <= m; x++) {
            cout << (vertical[x][y] ? '.' : 'Z');
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int edgeCount = 0, titanEdges = 0, chromeEdges = 0;
    initialize();
    readEdges(edgeCount, titanEdges, chromeEdges, n, m);

    int removedChrome = 0, removedTitan = 0;
    processEdges(edgeCount, removedChrome, removedTitan);

    printResults(edgeCount, removedChrome, removedTitan, chromeEdges, titanEdges, n, m);

    return 0;
}
