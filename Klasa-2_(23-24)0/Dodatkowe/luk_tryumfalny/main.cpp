#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1000002];
vector<bool> visited(1000002);

int tree(int x, int res) {
    int count = 0, sum = 0;
    visited[x] = true;

    for (int i = 0; i < graph[x].size(); i++) {
        if (!visited[graph[x][i]]) {
            count++;
            sum += tree(graph[x][i], res);
        }
    }

    return max(0, count + sum - res);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int r = n, l = 0;
    while (l < r) {
        int mid = (l + r) / 2;

        fill(visited.begin(), visited.end(), false);

        if (tree(1, mid) == 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}