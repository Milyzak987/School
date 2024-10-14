#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5e4 + 7;
vector<int> v(MAXN);

int mod(int x, int y) {
    if (x % y == 0)
        return x;
    return x % y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        r += v[i];
    }

    int res = -1, y = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        while (y < i || l < r) {
            y++;
            r -= v[mod(y, n)];
            l += v[mod(y, n)];
        }
        res = max(res, min(l, r));

        r += v[i];
        l -= v[i];
    }

    cout << res;
}
