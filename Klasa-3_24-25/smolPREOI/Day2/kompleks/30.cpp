#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 7;
vector<int> graph[MAXN];
bool visited[MAXN];
deque<int> up;
int ans[MAXN];

void dfs(int v) {
    visited[v] = 1;
    up.push_back(v);
    for (int u : graph[v]) {
        if (!visited[u]) {
            for(auto x : up){
                if(x > u){
                    ans[x]++;
                }
            }
            dfs(u);
        }
    }
    up.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}