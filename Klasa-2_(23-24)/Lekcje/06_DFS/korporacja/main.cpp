#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 500002;
vector<int> graph[MAXN];
vector<int> pre(MAXN), post(MAXN);
int counter = 1;

void dfs(int v, int p) {
    pre[v] = counter;
    counter++;
    for (int u : graph[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    post[v] = counter;
    counter++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }

    dfs(0, 0);

    while (true) {
        int a, b;
        cin >> a;
        if (a == -1) break;
        cin >> b;

        if (pre[a] < pre[b] && post[b] < post[a]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }

    return 0;
}
