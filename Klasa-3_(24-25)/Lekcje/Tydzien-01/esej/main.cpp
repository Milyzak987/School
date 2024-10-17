#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 2e9 + 7;
const int MAXN = 1e5 + 7;
vector<int> r(MAXN);
vector<int> l(MAXN);

int solve(int n, int m, string st1, string st2) {
    fill(r.begin(), r.begin() + m, INF);
    fill(l.begin(), l.begin() + m, -INF);

    int i1 = 0, i2 = 0;

    while (i1 < n && i2 < m) {
        if (st1[i1] == st2[i2]) {
            r[i2] = i1;
            i2++;
        }
        i1++;
    }

    i1 = n - 1;
    i2 = m - 1;

    while (i1 >= 0 && i2 >= 0) {
        if (st1[i1] == st2[i2]) {
            l[i2] = i1;
            i2--;
        }
        i1--;
    }

    if (r[m - 1] != INF || l[0] != -INF) return 0;

    int rig = 0;

    for (int i = 0; i < m; i++) {
        if (r[i] == INF && l[i] == -INF) {
            rig = i + 1;
        }
    }
    if (rig == m) {
        for (int i = 0; i < m; i++) {
            if (r[i] == INF) {
                return m - i;
            }
        }
    }

    int res = (rig > 0 ? rig : INF);
    for (int lewy = 0; lewy < m && r[lewy] != INF; lewy++) {
        while (rig < m && (rig <= lewy || l[rig] <= r[lewy])) {
            rig++;
        }
        res = min(res, rig - lewy - 1);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string st1, st2;
    cin >> st1 >> st2;

    int res = solve(n, m, st1, st2);

    reverse(st1.begin(), st1.end());
    reverse(st2.begin(), st2.end());
    int resRev = solve(n, m, st1, st2);

    cout << min(res, resRev);
}