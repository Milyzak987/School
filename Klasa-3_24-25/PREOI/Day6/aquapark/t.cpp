#include <bits/stdc++.h>
using namespace std;

struct Group {
    int id;
    int size;
    bool canSplit;
    int prefixSum; 
    
};

unordered_map<int, bool> removed;
deque<Group> groups;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    int groupId = 0;

    while (q--) {
        char type;
        cin >> type;

        if (type == 'D') {
            int z, c;
            cin >> z >> c;
            groups.push_back({++groupId, z, c == 1});
            removed[groupId] = false;
        } else if (type == 'R') {
            int i;
            cin >> i;
            removed[i] = true;
        } else if (type == 'P') {
            int m;
            cin >> m;

            vector<pair<int, int>> result;
            int j = 0;
            while (m > 0 && j != groups.size()) {
                Group front = groups[j];
                if (removed[front.id]) {
                    if (j == 0) {
                        groups.pop_front();
                    } else {
                        j++;
                    }
                    continue;
                }

                if (front.size <= m) {
                    removed[front.id] = true;
                    result.push_back({front.id, front.size});
                    m -= front.size;
                } else if (front.canSplit) {
                    result.push_back({front.id, m});
                    groups[j] = {front.id, front.size - m, front.canSplit};
                    m = 0;
                }
                j++;
            }

            cout << result.size() << '\n';
            for (auto &[id, count] : result) {
                cout << id << ' ' << count << '\n';
            }
        }
    }

    return 0;
}