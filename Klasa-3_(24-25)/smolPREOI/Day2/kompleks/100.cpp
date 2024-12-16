#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

vector<int> tree[MAXN];
int start[MAXN], finish[MAXN], euler[MAXN], result[MAXN];
int n, timer = 0;

vector<int> segTree(4 * MAXN, 0);

void update(int idx, int val, int l, int r, int pos) {
    if (l == r) {
        segTree[pos] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(idx, val, l, mid, 2 * pos + 1);
    } else {
        update(idx, val, mid + 1, r, 2 * pos + 2);
    }
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int query(int ql, int qr, int l, int r, int pos) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return segTree[pos];
    int mid = (l + r) / 2;
    return query(ql, qr, l, mid, 2 * pos + 1) +
           query(ql, qr, mid + 1, r, 2 * pos + 2);
}

void dfs(int node, int parent) {
    start[node] = ++timer;
    euler[timer] = node;
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
    finish[node] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Input
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        int node = euler[i];
        result[node] = query(1, node - 1, 1, n, 0);
        update(node, 1, 1, n, 0);
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}