#include <iostream>
using namespace std;
typedef long long ll;

const int R = 1 << 18;
ll tree[R * 2];

void update(int l, int r, int x) {
    l += R;
    r += R;
    tree[l] += x;
    if(l != r){
        tree[r] += x + r - l;
    }
    while (l/2 != r/2) {
        if (l % 2 == 0) {
            tree[l + 1] += x;
        }
        if (r % 2 == 1) {
            tree[r - 1] += x + 1;
        }
        l /= 2;
        r /= 2;
    }
}

int query(int v) {
    v += R;
    int res = 0;
    while (v > 0) {
        res += tree[v];
        v /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int n, m, q;
    // cin >> n >> m >> q;

    // for (int i = 0; i < m; i++) {
    //     int l, r;
    //     cin >> l >> r;
    //     update(l, r, 1);
    // }

    update(1, 50, 1);

    for (int i = 1; i <= 50; i++) {
        // cout << query(i) << "\n";
        cout << query(i) << "\n";
    }
}