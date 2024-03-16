#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e6 + 7;
vector<int> times(MAXN);

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    int count = 0, maxcount = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            times[j] += i;
        }
        for (int j = 1; j < n; j++) {
            if (times[j] / m == times[j - 1] / m + 1) {
                count++;
            } else {
                maxcount = max(count, maxcount);
                count = 0;
            }
        }
        maxcount = max(count, maxcount);
        count = 0;
    }

    cout << maxcount + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
