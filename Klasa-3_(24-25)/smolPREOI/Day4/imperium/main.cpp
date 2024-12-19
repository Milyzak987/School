#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF  = 1e9;

ll ceil(ll a, ll b) {
    if(b == 0){
        return INF;
    }
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

void solve(ll n, ll a, ll b) {
    ll res = 0, rem = n, capital = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (ceil(a, b) < rem && rem != 1) {
            res += b * (x - capital);
            res += a * (x - capital);
            capital = x;
        } else {
            res += b * (x - capital);
        }
        rem--;
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
}