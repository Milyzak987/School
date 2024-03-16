#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> graph[1000007];
vector<int> degree(1000007, 0);

void toposort(int n) {
    priority_queue<int, vector<int>, greater<int>> ready;
    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) ready.push(i);
    }

    if (ready.size() < 1) {
        cout << "NIE";
        return;
    }

    while (!ready.empty()) {
        int v = ready.top();
        ready.pop();
        order.push_back(v);
        for (auto u : graph[v]) {
            degree[u]--;
            if (degree[u] == 0) ready.push(u);
        }
    }
    if (order.size() != n)
        cout << "NIE";
    else {
        cout << "TAK\n";
        for (auto x : order) cout << x + 1 << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        degree[b - 1]++;
    }
    toposort(n);
}