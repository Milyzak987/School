#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int MAXN = 5e5 + 7;
const int LOG = 20;
vector<int> graph[MAXN];
set<Pair> enabled;
bool on[MAXN];
int preOrder[MAXN];
int jump[MAXN][LOG];
int depth[MAXN];
int t = 0;

void dfs(int v, int p) {
    preOrder[v] = ++t;
    jump[v][0] = p;
    for (int i = 1; i < LOG; i++) {
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    }

    for (auto u : graph[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) swap(v, u);

    for (int i = LOG; i >= 0; i--) {
        if (depth[jump[v][i]] >= depth[u]) {
            v = jump[v][i];
        }
    }

    if (v == u) return v;

    for (int i = LOG; i >= 0; i--) {
        if (jump[u][i] != jump[v][i]) {
            u = jump[u][i];
            v = jump[v][i];
        }
    }

    return jump[v][0];
}

int distance(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[LCA(a, b)];
}

int turn(int v, bool action, int& wynik) {
    auto upp = enabled.upper_bound({preOrder[v], 0});
    auto upd = upp;
    upd--;

    int up, ud;
    if (upp == enabled.end()) {
        up = (*enabled.begin()).second;
    } else {
        up = (*upp).second;
    }
    if (upp == enabled.begin()) {
        ud = (*enabled.rbegin()).second;
    } else {
        ud = (*upd).second;
    }

    int dif = 0;
    if (action) {
        dif += distance(v, up);
        dif += distance(v, ud);
        dif -= distance(ud, up);
    } else {
        dif -= distance(v, up);
        dif -= distance(v, ud);
        dif += distance(ud, up);
    }
    return dif;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    int res = 0;
    while (q--) {
        int v;
        cin >> v;
        if (on[v]) {
            on[v] = false;
            enabled.erase({preOrder[v], v});
            if (enabled.size() <= 1) {
                res = 0;
            } else {
                res += turn(v, true, res);
            }
        } else {
            on[v] = true;
            enabled.insert({preOrder[v], v});
            if (enabled.size() <= 1) {
                res = 0;
            } else {
                res += turn(v, false, res);
            }
        }
        cout << res / 2 << "\n";
    }
} 