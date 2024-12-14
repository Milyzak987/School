#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 1e6 + 7;
vector<pll> cost(MAXN);

bool comp(const pll a, const pll b) {
    if (a.first - a.second == b.first - b.second)
        return a.first < b.first;
    return a.first - a.second < b.first - b.second;
}

ll binarySearch(ll left, ll right, ll b, ll i) {
    while (left < right) {
        ll mid = (left + right) / 2;
        if (b - (cost[i].first - cost[i].second) * mid >= cost[i].first) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> cost[i].first;
    }
    for (ll i = 0; i < n; i++) {
        cin >> cost[i].second;
    }
    sort(cost.begin(), cost.begin() + n, comp);
    ll exp = 0;
    for (ll j = 0; j < m; j++) {
        int blocks;
        cin >> blocks;
        for (ll i = 0; i < n; i++) {
            if (blocks >= cost[i].first) {
                ll p = binarySearch(1, 1e9, blocks, i);
                blocks -= p * (cost[i].first - cost[i].second);
                exp += 2 * p;
            }
        }
    }

    cout << exp;
}