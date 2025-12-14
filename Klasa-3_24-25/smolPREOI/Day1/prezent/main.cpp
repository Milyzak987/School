#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

void solve(ll a, ll b) {
    ll p = a;
    ll maxres = 1;
    while (p * 2 <= b) {
        maxres++;
        p *= 2;
    }

    ll difres = 0;
    p /= a;

    difres = ((b / p) - a + 1) % MOD;
    ll q = max(p / 2, 1ll);
    if (a * 3 * q <= b) {
        ll x = (b / (3 * q)) - a + 1;
        x = (x * (maxres - 1)) % MOD;
        difres = (difres + x) % MOD;
    }
    cout << maxres << " " << difres << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        ll a, b;
        cin >> a >> b;
        solve(a, b);
    }
}