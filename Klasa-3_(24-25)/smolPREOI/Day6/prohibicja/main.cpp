#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;
int hungary[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    int minn = INF;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        hungary[i] = a % t;
        minn = min(minn, hungary[i]);
    }

    int maxx = -INF, minx = INF;
    for (int i = 0; i < n; i++) {
        if (hungary[i] - minn > minn - (hungary[i] - t)) {
            hungary[i] = hungary[i] - t;
        }
        maxx = max(maxx, hungary[i]);
        minx = min(minx, hungary[i]);
    }

    int dif = maxx - minx;

    // for (int i = 0; i < n; i++) {
    //     cout << hungary[i] << " ";
    // }
    // cout << "\n";

    cout << dif / 2 + (dif % 2 != 0);

    return 0;
}