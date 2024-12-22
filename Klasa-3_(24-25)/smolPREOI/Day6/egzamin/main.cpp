#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;
vector<unordered_map<int, int>> tree(4 * MAXN);
vector<int> arr(MAXN);

void segTree(int v, int start, int end) {
    if (start == end) {
        tree[v][arr[start]]++;
    } else {
        int mid = (start + end) / 2;
        segTree(2 * v, start, mid);
        segTree(2 * v + 1, mid + 1, end);
        for (const auto &[key, value] : tree[2 * v]) {
            tree[v][key] += value;
        }
        for (const auto &[key, value] : tree[2 * v + 1]) {
            tree[v][key] += value;
        }
    }
}

void update(int v, int start, int end, int idx, int oldX, int newX) {
    if (start == end) {
        tree[v][oldX]--;
        if (tree[v][oldX] == 0)
            tree[v].erase(oldX);
        tree[v][newX]++;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * v, start, mid, idx, oldX, newX);
        } else {
            update(2 * v + 1, mid + 1, end, idx, oldX, newX);
        }
        tree[v].clear();
        for (const auto &[key, value] : tree[2 * v]) {
            tree[v][key] += value;
        }
        for (const auto &[key, value] : tree[2 * v + 1]) {
            tree[v][key] += value;
        }
    }
}

int check(int v, int start, int end, int L, int R, int x) {
    if (R < start || end < L)
        return 0;
    if (L <= start && end <= R) {
        return tree[v].count(x) ? tree[v][x] : 0;
    }
    int mid = (start + end) / 2;
    return check(2 * v, start, mid, L, R, x) + check(2 * v + 1, mid + 1, end, L, R, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segTree(1, 0, n - 1);

    while (q--) {
        char c;
        cin >> c;
        if (c == '?') {
            int l, r, x;
            cin >> l >> r >> x;
            cout << check(1, 0, n - 1, l - 1, r - 1, x) << "\n";
        } else {
            int idx, x;
            cin >> idx >> x;
            update(1, 0, n - 1, idx - 1, arr[idx - 1], x);
            arr[idx - 1] = x;
        }
    }

    return 0;
}