#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> para;

const int MAXN = 2e5 + 7;
const int LOG = 30;
vector<int> graf[MAXN];
int p[MAXN][LOG + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> p[i][0];
    }

    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j <= n; j++) {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;

        int res = x;
        for (int i = LOG; i >= 0; i--) {
            if ((1 << i) > k) continue;
            k -= (1 << i);
            res = p[res][i];
        }
        cout << res << "\n";
    }

    return 0;
}