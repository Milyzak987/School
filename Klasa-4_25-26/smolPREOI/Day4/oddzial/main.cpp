#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXT = 1e6 + 7;
const int MAXN = 3e5 + 7;
const int R = 1 << 19;
vector<pii> treeMinMax(2 * R, {0, INT_MAX});
vector<int> treePrev(2 * R, 0);
set<int> positions[MAXT];
int S[MAXN];

int getPredecessor(int val, int idx) {
    auto it = positions[val].lower_bound(idx);

    if (it == positions[val].begin()) return 0;

    it--;
    return *it;
}

int getSuccessor(int val, int idx) {
    auto it = positions[val].upper_bound(idx);

    if (it == positions[val].end()) return 0;

    return *it;
}

void updateMinMax(int i, int x) {
    i += R;
    treeMinMax[i].first = x;
    treeMinMax[i].second = x;
    i /= 2;
    while (i > 0) {
        treeMinMax[i].first = max(treeMinMax[i * 2].first, treeMinMax[i * 2 + 1].first);
        treeMinMax[i].second = min(treeMinMax[i * 2].second, treeMinMax[i * 2 + 1].second);
        i /= 2;
    }
}

pii queryMinMax(int a, int b) {
    int resMax = 0;
    int resMin = INT_MAX;
    a += R - 1;
    b += R + 1;
    while (a / 2 != b / 2) {
        if (a % 2 == 0) {
            resMax = max(resMax, treeMinMax[a + 1].first);
            resMin = min(resMin, treeMinMax[a + 1].second);
        }
        if (b % 2 == 1) {
            resMax = max(resMax, treeMinMax[b - 1].first);
            resMin = min(resMin, treeMinMax[b - 1].second);
        }
        a /= 2;
        b /= 2;
    }
    return {resMax, resMin};
}

void updatePrev(int i, int x) {
    i += R;
    treePrev[i] = x;
    i /= 2;
    while (i > 0) {
        treePrev[i] = max(treePrev[i * 2], treePrev[i * 2 + 1]);
        i /= 2;
    }
}

int queryPrev(int a, int b) {
    int res = 0;
    a += R - 1;
    b += R + 1;
    while (a / 2 != b / 2) {
        if (a % 2 == 0) res = max(res, treePrev[a + 1]);
        if (b % 2 == 1) res = max(res, treePrev[b - 1]);
        a /= 2;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, q;
    cin >> n >> t >> q;

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        updateMinMax(i, S[i]);
        positions[S[i]].insert(i);
    }

    for (int val = 1; val <= t; val++) {
        int last_pos = 0;
        for (int pos : positions[val]) {
            updatePrev(pos, last_pos);
            last_pos = pos;
        }
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r;
            cin >> l >> r;

            if (queryPrev(l, r) >= l) {
                cout << "NIE\n";
                continue;
            }

            pii mm = queryMinMax(l, r);
            if ((mm.first - mm.second) == (r - l)) {
                cout << "TAK\n";
            } else {
                cout << "NIE\n";
            }
        } else {
            int p, v;
            cin >> p >> v;
            int old_v = S[p];

            if (old_v == v) continue;

            int old_pre = getPredecessor(old_v, p);
            int old_suc = getSuccessor(old_v, p);

            if (old_suc != 0) {
                updatePrev(old_suc, old_pre);
            }
            positions[old_v].erase(p);

            updatePrev(p, 0);

            positions[v].insert(p);

            int new_pre = getPredecessor(v, p);
            int new_suc = getSuccessor(v, p);

            updatePrev(p, new_pre);

            if (new_suc != 0) {
                updatePrev(new_suc, p);
            }

            S[p] = v;
            updateMinMax(p, v);
        }
    }

    return 0;
}
