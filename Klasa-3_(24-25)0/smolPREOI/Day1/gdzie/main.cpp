#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;
int A[MAXN];
int B[MAXN];
bool visited[MAXN];
vector<int> graph[MAXN];

void DFS(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) DFS(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < n; i++) {
        graph[A[i]].push_back(B[i]);
    }

    int res = 1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            res = (res * 2) % MOD;
            DFS(i);
        }
    }
    cout << res;
}