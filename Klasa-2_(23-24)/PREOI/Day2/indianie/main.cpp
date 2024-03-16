#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bitset<64>> bisonsSurvival(m);

    for (int i = 0; i < m; ++i) {
        int xi, yi;
        cin >> xi >> yi;
        bisonsSurvival[i].set(xi - 1);
        bisonsSurvival[i].set(yi - 1);
    }

    int count = 0;

    for (int v = 0; v < n; ++v) {
        bitset<64> Sv;
        Sv.set(v);

        for (int t = m - 1; t >= 0; --t) {
            bitset<64> temp = Sv;
            Sv |= bisonsSurvival[t];
            Sv &= temp;
        }

        for (int u = v + 1; u < n; ++u) {
            if (Sv[u] && Sv[v]) {
                cout << u + 1 << " " << v + 1 << endl;
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
