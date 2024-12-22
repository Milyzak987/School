#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;
const int R = 1 << 18;
vector<map<int, int>> tree(R * 2);
vector<int> arr(MAXN);

void update(int v, int x) {
    int oldVal = arr[v];
    arr[v] = x;
    v += R;
    while (v > 0) {
        tree[v][oldVal]--;
        tree[v][x]++;
        v /= 2;
    }
}

int query(int l, int r, int x) {
    l += R;
    r += R;
    long long res = tree[l][x];
    if (l != r) {
        res += tree[r][x];
    }
    while (l / 2 != r / 2) {
        {
            if (l % 2 == 0)
                res += tree[l + 1][x];
            if (r % 2 == 1)
                res += tree[r - 1][x];
            l /= 2;
            r /= 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }

    while (q--) {
        char c;
        cin >> c;
        if (c == '?') {
            int l, r, x;
            cin >> l >> r >> x;
            cout << query(l, r, x) << "\n";
        } else {
            int a, x;
            cin >> a >> x;
            update(a, x);
        }
    }

    return 0;
}