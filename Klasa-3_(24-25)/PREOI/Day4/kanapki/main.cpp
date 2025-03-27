#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll INF = 1e18;
const ll MAXN = 1e5 + 7;
Pair cost[MAXN];
ll ingredients[MAXN];

ll solve(ll t, ll n) {
    ll res = INF;
    for (ll i = 0; i < n; i++) {
        if(ingredients[i] < t * cost[i].first){
            continue;
        }
        res = min(res, (ingredients[i] - (t * cost[i].first)) / cost[i].second) + t;
    }
    return res;
}

ll ternarySearch(ll l, ll r, ll n) {
    while (l < r) {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = solve(m1, n);
        ll f2 = solve(m2, n);
        if (f1 < f2) {
            l = m1 + 1;
        } else if (f1 > f2) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    // cout << l << "x";
    return solve(l, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    bool podZadanie = true;

    for (ll i = 0; i < n; i++) {
        cin >> ingredients[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> cost[i].first;
    }
    for (ll i = 0; i < n; i++) {
        cin >> cost[i].second;
        if (cost[i].second != cost[i].first) {
            podZadanie = false;
        }
    }

    ll minMax = INF;
    for (int i = 0; i < n; i++) {
        minMax = min(minMax, ingredients[i] / cost[i].first);
    }

    cout << ternarySearch(0, minMax, n);
}
