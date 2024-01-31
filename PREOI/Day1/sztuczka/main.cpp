#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 7;
vector<long long> pos(MAXN);
vector<int> moves(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }

    int q;
    long long m;
    cin >> q >> m;
    for (int i = 0; i < q; i++) {
        cin >> moves[i];
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < q; i++) {
            int a, a1, a2;
            a = moves[i];
            if (pos[a - 1] < pos[a]) {
                int ldis = abs(pos[a - 1] - pos[a]);
                a1 = pos[a - 1] - ldis;
            } else {
                int ldis = abs(pos[a] - pos[a - 1]);
                a1 = pos[a - 1] + ldis;
            }
            if (pos[a + 1] > pos[a]) {
                int rdis = abs(pos[a] - pos[a + 1]);
                a2 = pos[a + 1] + rdis;
            } else {
                int rdis = abs(pos[a + 1] - pos[a]);
                a2 = pos[a + 1] - rdis;
            }
            pos[a] = (a1 + a2) / 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << pos[i] << " ";
    }
    return 0;
}