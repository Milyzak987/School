#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll count;
    int pref;
    int suff;
    int len;
    int l_val;
    int r_val;
};

const int MAXN = 2e5 + 5;
int arr[MAXN];
Node tree[4 * MAXN];

Node merge(const Node& left, const Node& right) {
    Node res;
    res.len = left.len + right.len;
    res.l_val = left.l_val;
    res.r_val = right.r_val;

    res.count = left.count + right.count;

    if (left.r_val <= right.l_val) {
        res.count += (ll)left.suff * right.pref;

        if (left.pref == left.len) {
            res.pref = left.len + right.pref;
        } else {
            res.pref = left.pref;
        }

        if (right.suff == right.len) {
            res.suff = right.len + left.suff;
        } else {
            res.suff = right.suff;
        }
    } else {
        res.pref = left.pref;
        res.suff = right.suff;
    }

    return res;
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = {1, 1, 1, 1, arr[start], arr[start]};
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = {1, 1, 1, 1, val, val};
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
}

Node query(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    if (r <= mid) {
        return query(2 * node, start, mid, l, r);
    }

    if (l > mid) {
        return query(2 * node + 1, mid + 1, end, l, r);
    }

    Node p1 = query(2 * node, start, mid, l, r);
    Node p2 = query(2 * node + 1, mid + 1, end, l, r);
    return merge(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            update(1, 1, n, x, y);
        } else {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            cout << res.count << "\n";
        }
    }

    return 0;
}