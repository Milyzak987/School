#include <bits/stdc++.h>
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


    ll limitL1 = -abs(sqrt(abs(l) + 1) + 1) - 1;
    limitL1 = -abs(limitL1 * max(abs(l), abs(r)));
    ll limitL2 = -abs(1 - sqrt(abs(r) + 1)) - 1;
    limitL2 = -abs(limitL2 * max(abs(l), abs(r)));
    ll limitL = min(limitL1, limitL2);

    ll limitR1 = abs(sqrt(abs(r) + 1) + 1) + 1;
    limitR1 = limitR1 * max(abs(l), abs(r));
    ll limitR2 = abs(1 - sqrt(abs(l) + 1)) + 1;
    limitR2 = limitR2 * max(abs(l), abs(r));
    ll limitR = max(limitR1, limitR2);

    for (ll x1 = limitL; x1 <= limitR; x1++) {
        for (ll x2 = x1; x2 <= limitR; x2++) {
            ll b = -(x1 + x2);
            ll c = x1 * x2;
            ll sum = b + c;
            if (l <= sum && sum <= r) {
                res++;
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