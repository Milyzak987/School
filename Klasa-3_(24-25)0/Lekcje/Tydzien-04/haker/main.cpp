#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 5e5 + 7;
int pcs[MAXN * 2];
int pref[MAXN * 2];
int frag[MAXN * 2];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int h = (n + 1) / 2;

    for (int i = 1; i <= n; i++) {
        cin >> pcs[i];
        pref[i] = pref[i - 1] + pcs[i];
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        pcs[i] = pcs[i - n];
        pref[i] = pref[i - 1] + pcs[i];
    }

    for (int i = 1; i <= 2 * n; i++) {
        frag[i] = pref[i + h - 1] - pref[i - 1];
    }

    for (int i = 1; i < h; i++) {
        pq.push({frag[i], i});
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        int e = i + h - 1;
        pq.push({frag[e], e});

        while (pq.top().second < i) pq.pop();

        res = max(res, pq.top().first);
    }

    cout << res;

    return 0;
}
