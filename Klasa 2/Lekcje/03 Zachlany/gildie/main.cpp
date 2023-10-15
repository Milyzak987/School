#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> graph(200003);
vector<int> res(200003);
vector<bool> visit(200003, false);

void DFS(int start) {
    stack<int> s;
    s.push(start);
    visit[start] = true;
    res[start] = 0;

    while (!s.size() == 0) {
        int t = s.top();
        s.pop();

        for (auto x : graph[t]) {
            if (!visit[x]) {
                visit[x] = true;
                res[x] = (res[t] == 0) ? 1 : 0;
                s.push(x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (graph[i].size() == 0) {
            cout << "NIE";
            return 0;
        }
        if (!visit[i]) {
            DFS(i);
        }
    }
    cout << "TAK" << endl;

    for (int i = 1; i <= n; i++) {
        if (res[i] == 0)
            cout << "K" << endl;
        else
            cout << "S" << endl;
    }
}