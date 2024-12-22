#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll MAXN = 1 << 21;
vector<Pair> dp(MAXN, {LLONG_MAX, -1});

void computeDP(int k) {
    ll R = 1 << k;
    for (ll i = R; i >= 0; i--) {
        for (ll j = 0; j < k; j++) {
            dp[i] = min(dp[i], dp[i | (1 << j)]);
        }
    }
}

void query() {
    ll t, dress = 0;
    cin >> t;
    for (ll j = 0; j < t; j++) {
        ll x;
        cin >> x;
        dress |= 1 << (x - 1);
    }
    if (dp[dress].second == -1) {
        cout << "NIE\n";
    } else {
        cout << dp[dress].second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, q;
    cin >> n >> k >> q;

    for (ll i = 1; i <= n; i++) {
        ll cost, t, dress = 0;
        cin >> cost >> t;
        for (ll j = 0; j < t; j++) {
            ll x;
            cin >> x;
            dress |= 1 << (x - 1);
        }
        if (cost < dp[dress].first) {
            dp[dress] = {cost, i};
        }
    }

    computeDP(k);

    while (q--) {
        query();
    }
}