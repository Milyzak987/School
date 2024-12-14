#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

void solve(ll a, ll b) {
    ll p = a;
    int maxres = 1;
    while (p * 2 <= b) {
        maxres++;
        p *= 2;
    }

    ll difres = 0;
    p /= a;
    while (a * p <= b) {
        difres = (difres + 1) % MOD;
        if (a * p / 2 * 3 <= b) {
            difres = (difres + maxres - 1) % MOD;
        }
        a++;
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