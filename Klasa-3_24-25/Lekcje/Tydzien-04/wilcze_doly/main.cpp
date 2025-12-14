#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 2e6 + 7;
const int R = (1 << 21);
int holes[MAXN];
ll pref[MAXN];
ll planks[MAXN];
priority_queue<pair<ll, int>> pq;

ll g(int l) {
    if (pq.empty()) return 0;
    pair<ll, int> p;
    while ((p = pq.top()).second < l) {
        pq.pop();
        if (pq.empty()) return 0;
    }
    return p.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    ll p;
    cin >> n >> p >> d;

    for (int i = 1; i <= n; i++) {
        cin >> holes[i];
        pref[i] = pref[i - 1] + holes[i];
    }

    for (int i = 1; i <= n - d + 1; i++) {
        int e = i + d - 1;
        if (i > e) {
            planks[i] = 0;
        } else {
            planks[i] = pref[e] - pref[i - 1];
        }
    }

    int res = d;

    ll hole = 0;
    int l = 1;
    for (int p = 1; p <= n; p++) {
        hole += holes[p];

        int x = p - d + 1;
        if (x >= 1) {
            pq.push({planks[x], x});
        }

        while (l + d < p && hole - g(l) > p) {
            hole -= holes[l];
            l++;
        }

        if (hole - g(l) <= p) {
            res = max(res, p - l + 1);
        }
    }

    cout << res;

    return 0;
}