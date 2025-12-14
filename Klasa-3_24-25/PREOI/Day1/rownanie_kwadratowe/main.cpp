#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
    ll l, r;
    cin >> l >> r;

    if (l <= 0 && r >= 0) {
        cout << -1 << "\n";
        return;
    }

    ll res = 0;

    for (ll x1 = -(l * l); x1 <= (r * r); x1++) {
        for (ll x2 = x1; x2 <= (r * r); x2++) {
            ll b = -(x1 + x2);
            ll c = x1 * x2;
            ll sum = b + c;
            if (l <= sum && sum <= r) {
                res++;
                cout << x1 << " " << x2 << "\n";
            }
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}