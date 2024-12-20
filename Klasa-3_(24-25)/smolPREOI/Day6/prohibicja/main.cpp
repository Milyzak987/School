#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;
int hungary[MAXN];  // 🇭🇺🇭🇺🇭🇺🇭🇺

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
    }

    sort(hungary, hungary + n);

    int dif = hungary[n - 1] - hungary[0];

    for (int i = 0; i < n - 1; i++) {
        dif = min(dif, hungary[i] - (hungary[i + 1] - t));
    }

    cout << dif / 2 + (dif % 2 != 0);

    return 0;
}