#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000005;
int sscNumber[MAXN];
int sscSize[MAXN];
int dp[MAXN];
vector<bool> visited(MAXN);
vector<int> postOrder;
vector<int> graph[MAXN];
vector<int> reversedGraph[MAXN];
vector<int> newGraph[MAXN];

void ssfs(int v, int x) {
    visited[v] = true;
    sscNumber[v] = x;
    for (int i = 0; i < reversedGraph[v].size(); ++i) {
        if (!visited[reversedGraph[v][i]]) {
            ssfs(reversedGraph[v][i], x);
        }
    }
}

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i) {
        if (!visited[graph[v][i]]) {
            dfs(graph[v][i]);
        }
    }
    postOrder.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
        reversedGraph[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i <= n; ++i) {
        visited[i] = false;
    }

    int counter = 0;
    while (!postOrder.empty()) {
        int backValue = postOrder.back();
        if (!visited[backValue]) {
            ssfs(backValue, counter);
            postOrder.pop_back();
            counter++;
        } else {
            postOrder.pop_back();
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < reversedGraph[i].size(); j++) {
            if (sscNumber[i] != sscNumber[reversedGraph[i][j]]) {
                newGraph[sscNumber[i]].push_back(sscNumber[reversedGraph[i][j]]);
            } else {
                sscSize[sscNumber[i]]++;
            }
        }
    }

    for (int i = 0; i < counter; ++i) {
        int maxVal = 0;
        for (int j = 0; j < newGraph[i].size(); j++) {
            maxVal = max(dp[newGraph[i][j]] + 1, maxVal);
        }
        dp[i] = maxVal + sscSize[i];
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[sscNumber[i]] << "\n";
    }

    return 0;
}