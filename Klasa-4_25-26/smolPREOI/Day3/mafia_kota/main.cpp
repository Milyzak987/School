#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> para;

const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 2e9 + 7;

int cost[MAXN];
vector<int> graph[MAXN];

int num[MAXN];
int low[MAXN];
int ii;
bool onStack[MAXN];
stack<int> st;

ll res = 0;
ll ways = 1;

void findSCC(int u) {
    ii++;
    num[u] = ii;
    low[u] = ii;
    st.push(u);
    onStack[u] = true;

    for (int v : graph[u]) {
        if (num[v] == -1) {
            findSCC(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        int min_c = INF;
        int cnt = 0;

        while (true) {
            int v = st.top();
            st.pop();
            onStack[v] = false;

            if (cost[v] < min_c) {
                min_c = cost[v];
                cnt = 1;
            } else if (cost[v] == min_c) {
                cnt++;
            }

            if (u == v) break;
        }

        res += min_c;
        ways = (ways * cnt) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];

        num[i] = -1;
        low[i] = -1;
        onStack[i] = false;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == -1) {
            findSCC(i);
        }
    }

    cout << res << " " << ways << "\n";

    return 0;
}