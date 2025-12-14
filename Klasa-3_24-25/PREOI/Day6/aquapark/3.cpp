#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 7;
const int R = 1 << 18;
vector<int> tree(2 * R);
deque<pair<int, bool>> groups;
unordered_map<int, bool> removed;
int groupId = 0;

void update(int pos, int val) {
    pos += R;
    tree[pos] = val;
    while (pos > 1) {
        pos /= 2;
        tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
    }
}

int query(int l, int r) {
    l += R;
    r += R;
    int wynik = 0;
    while (l <= r) {
        if (l % 2 == 1) wynik += tree[l++];
        if (r % 2 == 0) wynik += tree[r--];
        l /= 2;
        r /= 2;
    }
    return wynik;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        char type;
        cin >> type;

        if (type == 'D') {
            int z, c;
            cin >> z >> c;
            groups.push_back({z, c == 1});
            update(groupId, z);
            removed[groupId] = false;
            groupId++;
        } else if (type == 'R') {
            int i;
            cin >> i;
            removed[i - 1] = true;
            update(i - 1, 0);
        } else if (type == 'P') {
            int m;
            cin >> m;

            vector<pair<int, int>> result;
            int remaining = m;
            
            for (int i = 0; i < groupId; i++) {
                if (removed[i]) continue;
                auto &[size, canSplit] = groups[i];

                if (size <= remaining) {
                    removed[i] = true;
                    update(i, 0);
                    result.push_back({i + 1, size});
                    remaining -= size;
                } else if (canSplit) {
                    result.push_back({i + 1, remaining});
                    groups[i].first -= remaining;
                    update(i, groups[i].first);
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
