#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 7;
const int R = 1 << 20;
vector<int> tree(2 * R);
vector<int> graph[MAXN];
pll order[MAXN];

void dfs(int v, int p, int &ord) {
    ord++;
    order[v].first = ord;
    for (auto u : graph[v]) {
        if (u != p) {
            dfs(u, v, ord);
        }
    }
    order[v].second = ord;
}

void update(int v) {
    v += R;
    tree[v] = 1;
    while (v > 1) {
        v /= 2;
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int query(int l, int r) {
    l += R;
    r += R;
    int wynik = tree[l];
    if (l != r)
        wynik += tree[r];
    while (l / 2 != r / 2) {
        if (l % 2 == 0) {
            wynik += tree[l + 1];
        }
        if (r % 2 == 1) {
            wynik += tree[r - 1];
        }
        l /= 2;
        r /= 2;
    }
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ord = 0;
    dfs(1, 1, ord);

    for (int i = 1; i <= n; i++) {
        cout << query(order[i].first, order[i].second) << "\n";
        update(order[i].first);
    }
}