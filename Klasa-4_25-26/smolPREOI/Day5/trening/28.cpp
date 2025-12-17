#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 7;
vector<int> graph[MAXN];
vector<int> disabled(MAXN);
vector<bool> isDisabled(MAXN, false);
vector<int> dist(MAXN, -1);

void subtask1(int n, int q) {
    for (int k = 0; k < q; ++k) {
        int t, x;
        cin >> t >> x;

        for (int i = 0; i < x; ++i) {
            cin >> disabled[i];
        }

        sort(disabled.begin(), disabled.begin() + x);

        int fur = 1;
        for (int i = 0; i < x; ++i) {
            int block = disabled[i];
            if (block == fur) {
                fur++;
            } else if (block > fur) {
                break;
            }
        }

        if (fur > t) {
            cout << -1 << "\n";
        } else {
            cout << (t - fur) << "\n";
        }
    }
}

void subtask23(int n, int start_node) {
    dist[start_node] = 0;

    for (int u = n; u >= 1; --u) {
        if (dist[u] != -1) {
            for (int v : graph[u]) {
                if (dist[u] + 1 > dist[v]) {
                    dist[v] = dist[u] + 1;
                }
            }
        }
    }

    int maxl = -1;

    for (int i = 1; i <= n; ++i) {
        if (dist[i] != -1 && !isDisabled[i]) {
            if (dist[i] > maxl) {
                maxl = dist[i];
            }
        }
    }

    cout << maxl << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        graph[v].push_back(u);
    }

    if (q == 1) {
        int t, x;
        cin >> t >> x;
        int a;
        for (int i = 0; i < x; ++i) {
            cin >> a;
            isDisabled[a] = true;
        }

        subtask23(n, t);
    } else {
        subtask1(n, q);
    }

    return 0;
}