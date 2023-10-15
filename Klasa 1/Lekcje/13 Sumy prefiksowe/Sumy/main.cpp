#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e3 + 7;
int sumyPref[MAXN][MAXN], a, b, c, d, n, m, q, i, j;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            cin >> sumyPref[i][j];
            sumyPref[i][j] += sumyPref[i - 1][j] + sumyPref[i][j - 1] -
                              sumyPref[i - 1][j - 1];
        }
    }
    cin >> q;
    for (i = 0; i < q; ++i) {
        cin >> a >> b >> c >> d;
        cout << sumyPref[c][d] - sumyPref[a - 1][d] - sumyPref[c][b - 1] +
                    sumyPref[a - 1][b - 1]
             << '\n';
    }
}