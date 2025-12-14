#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    void update(int pos, int val) {
        pos += size;
        tree[pos] = val;
        while (pos > 1) {
            pos /= 2;
            tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
        }
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int mid = (lx + rx) / 2;
        return query(l, r, 2 * x, lx, mid) + query(l, r, 2 * x + 1, mid, rx);
    }

    int query(int l, int r) {
        return query(l, r, 1, 0, size);
    }
};

struct Group {
    int size;
    bool canSplit;
};

vector<Group> groups;
SegmentTree segTree(200000);
unordered_map<int, bool> removed;
int groupId = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        char type;
        cin >> type;

        if (type == 'D') {
            int z, c;
            cin >> z >> c;
            groups.push_back({z, c == 1});
            segTree.update(groupId, z);
            removed[groupId] = false;
            groupId++;
        } else if (type == 'R') {
            int i;
            cin >> i;
            removed[i - 1] = true;
            segTree.update(i - 1, 0);
        } else if (type == 'P') {
            int m;
            cin >> m;

            vector<pair<int, int>> result;
            int remaining = m;
            
            for (int i = 0; i < groupId; i++) {
                if (removed[i]) continue;
                Group &g = groups[i];

                if (g.size <= remaining) {
                    removed[i] = true;
                    segTree.update(i, 0);
                    result.push_back({i + 1, g.size});
                    remaining -= g.size;
                } else if (g.canSplit) {
                    result.push_back({i + 1, remaining});
                    groups[i].size -= remaining;
                    segTree.update(i, groups[i].size);
                    remaining = 0;
                }

                if (remaining == 0) break;
            }

            cout << result.size() << "\n";
            for (auto &[id, count] : result) {
                cout << id << " " << count << "\n";
            }
        }
    }
    return 0;
}