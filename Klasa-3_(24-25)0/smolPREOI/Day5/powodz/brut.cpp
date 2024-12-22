#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MAXN = 1e6 + 7;
ll val[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        val[i] = b;
    }

    sort(val, val + n, greater<ll>());

    ll res = 0;

    if (k > n) {
        for (ll i = 0; i < n; i++) {
            res += val[i];
        }
        res *= k/n;
        for(int i = 0; i < k % n; i++){
            res += val[i];
        }
    }

    cout << res;

    return 0;
}