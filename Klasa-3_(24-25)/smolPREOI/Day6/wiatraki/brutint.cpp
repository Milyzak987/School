#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MAXN = 2007;
const ll INF = 9e18;
vector<vector<ll>> mat(MAXN, vector<ll>(MAXN));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> mat[i][j];

    ll minCost = INF;
    ll bestA = 0, bestB = 0;

    for (ll a = 0; a <= n; ++a) {
        for (ll b = 0; b <= m; ++b) {
            ll cost = 0;

            for (ll i = 0; i < n; ++i) {
                for (ll j = 0; j < m; ++j) {
                    ll wiatrakX = 2 * i + 1;
                    ll wiatrakY = 2 * j + 1;
                    ll obozX = 2 * a;
                    ll obozY = 2 * b;

                    ll dx = 4 * (wiatrakX - obozX);
                    ll dy = 4 * (wiatrakY - obozY);
                    ll d2 = dx * dx + dy * dy;

                    cost += mat[i][j] * d2;
                }
            }

            if (cost < minCost) {
                minCost = cost;
                bestA = a;
                bestB = b;
            }
        }
    }

    cout << minCost << "\n" << bestA << " " << bestB << "\n";
    return 0;
}