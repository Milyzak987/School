#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 7;
vector<long long> pos(MAXN);
vector<long long> pos_old(MAXN);
vector<int> moves(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    pos_old = pos;
    int q;
    long long m;
    cin >> q >> m;
    for (int i = 0; i < q; i++) {
        cin >> moves[i];
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < q; i++) {
            int a;
            a = moves[i];
            pos[a] = pos[a - 1] + pos[a + 1] - pos[a];
        }
        if (pos == pos_old) {
            for (int k = 0; k < (m % (j+1)); k++) {
                for (int i = 0; i < q; i++) {
                    int a;
                    a = moves[i];
                    pos[a] = pos[a - 1] + pos[a + 1] - pos[a];
                }
            }
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << pos[i] << " ";
    }
    return 0;
}