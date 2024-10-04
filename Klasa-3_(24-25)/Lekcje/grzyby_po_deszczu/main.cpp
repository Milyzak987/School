#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 7;
vector<long long> dis(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> dis[i];
    }

    if (n == 1) {
        cout << dis[1] * (t / 2 + 1);
        return 0;
    }

    long long res = 0, s = 0;
    for (int i = 1; i < n; i++) {
        int l = t - i + 1;

        if (l < 0) break;

        s += dis[i];
        long long cur = s;
        cur += (dis[i] + dis[i + 1]) * (l / 2);
        
        if (l % 2 == 1) cur += dis[i + 1];

        res = max(res, cur);
    }
    cout << res;
}