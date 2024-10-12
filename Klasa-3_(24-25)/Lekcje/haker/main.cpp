#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 5e5 + 7;
int pcs[MAXN];
int pref[MAXN];
int sums[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pcs[i];
        pref[i + 1] = pref[i] + pcs[i];
    }

    int h = (n + 1) / 2;
    for (int i = 0; i < n; i++) {
        if (i + h > n) {
            sums[i] = pref[n] - pref[i] + pref[(i + h) % n];
        } else {
            sums[i] = pref[i + h] - pref[i];
        }
    }

    for (int i = 0; i < h - 1; i++){
        q.push({sums[i], i});
    }

    int res = 0;
    for (int i = 0; i < n; i++){
        int e = i + h;
        q.push({sums[e], e});

        while (q.top().second < i) q.pop();

        res = max(res, q.top().first);
    }

    cout << res;

    return 0;
}