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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool podZadanie = true;

    for (int i = 0; i < n; i++) {
        cin >> ingredients[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i].second;
        if (cost[i].second != cost[i].first) {
            podZadanie = false;
        }
    }

    if (podZadanie) {
        ll res = INF;
        for (ll ii = 0; ii < n; ii++) {
            res = min(res, (ingredients[ii] / cost[ii].second));
        }
        cout << res;
        return 0;
    }

    ll minMaxA = INF;
    ll minMaxB = INF;
    for (int i = 0; i < n; i++) {
        minMaxA = min(minMaxA, ingredients[i] / cost[i].first);
        minMaxB = min(minMaxB, ingredients[i] / cost[i].second);
    }

    bool Asmaller = minMaxA < minMaxB;
    ll minMax = min(minMaxA, minMaxB), res = 0;

    // cout << minMaxA << "\n";

    for (ll i = 0; i <= minMax; i++) {
        ll cur = INF;
        for (ll ii = 0; ii < n; ii++) {

            if (Asmaller) {
                if (i * cost[ii].first > ingredients[ii]) {
                    continue;
                }
                cur = min(cur, (ingredients[ii] - (i * cost[ii].first)) / cost[ii].second) + i;
            } else {
                if (i * cost[ii].second > ingredients[ii]) {
                    continue;
                }
                cur = min(cur, (ingredients[ii] - (i * cost[ii].second)) / cost[ii].first) + i;
            }
            // cout << cur << "x\n";
        }
        res = max(res, cur);
    }
    cout << res;
}