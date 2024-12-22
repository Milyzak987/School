#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll MAXN = 1e5 + 7;
ll added[MAXN];
Pair steal[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, A, B;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> added[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> steal[i].first;
    }
    for (ll i = 0; i < n; i++) {
        cin >> steal[i].second;
    }
    cin >> A >> B;

    ll curSum = 0;
    for (int i = n - 1; i >= 0; i--) {
        steal[i].first += curSum;
        steal[i].second += curSum;
        curSum += added[i];
    }
    A += curSum;
    B += curSum;

    sort(steal, steal + n);

    ll res = 0, minn = B;
    for (ll i = 0; i < n; i++) {
        ll x = min(A, steal[i].first);
        res = max(res, x + minn);
        minn = min(minn, steal[i].second);
    }
    res = max(res, minn + A);

    cout << res;
}