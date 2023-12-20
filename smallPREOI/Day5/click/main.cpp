#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct Edge {
    double distance;
    int v1, v2;
};
const int MAXN = 2007;
vector<pair<int, int>> coordinates(MAXN);
vector<int> representative(MAXN);
vector<Edge> edges;

bool compareEdges(Edge e1, Edge e2) {
    return e1.distance > e2.distance;
}

int Find(int v) {
    if (v == representative[v]) return v;
    representative[v] = Find(representative[v]);
    return representative[v];
}

void Union(int v1, int v2) {
    int x = Find(v1);
    int y = Find(v2);
    if (x == y) return;
    representative[x] = representative[y];
}

void readInput(int& n) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        double x, y;
        cin >> x >> y;
        representative[i] = i;
        coordinates[i] = {x, y};
    }
    representative[0] = 0;
    coordinates[0] = {0, 0};
}

void calculateDistances(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == j) continue;
            double xDiff = abs(coordinates[i].first - coordinates[j].first);
            double yDiff = abs(coordinates[i].second - coordinates[j].second);
            edges.push_back({sqrt(xDiff * xDiff + yDiff * yDiff), i, j});
        }
    }
}

void findMaximumDistance() {
    sort(edges.begin(), edges.end(), compareEdges);
    double result = 0;
    while (!edges.empty()) {
        auto [distance, v1, v2] = edges.back();
        edges.pop_back();
        if (Find(v1) != Find(v2)) {
            result = max(result, distance);
            Union(v1, v2);
        }
    }
    cout << fixed << setprecision(5) << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    readInput(n);
    calculateDistances(n);
    findMaximumDistance();
}