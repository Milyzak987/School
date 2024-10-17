#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;
const int MAXN = 2e5 + 7;
long long t[MAXN];
long long pref[MAXN];

deque<long long> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        pref[i] = pref[i - 1] + t[i];
    }

    long long res = -INF;
    for (int i = 1; i < b; i++) {
        while (!dq.empty() && pref[dq.front()] <= pref[i]) {
            dq.pop_front();
        }
        dq.push_front(i);
    }

    for (int i = 0; i <= (n - a); i++) {
        while (i + b <= n && !dq.empty() && pref[dq.front()] <= pref[i + b]) {
            dq.pop_front();
        }

        if (i + b <= n)
            dq.push_front(i + b);

        while (!dq.empty() && dq.back() < (a + i)) {
            dq.pop_back();
        }

        res = max(res, pref[dq.back()] - pref[i]);
    }

    cout << res;
}
