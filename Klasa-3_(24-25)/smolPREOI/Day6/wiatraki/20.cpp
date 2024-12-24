#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MAXN = 2007;
const ll INF = 9e18;
vector<vector<ll>> c(MAXN, vector<ll>(MAXN));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < n; ++i)
        for (ll j = 0; j < m; ++j)
            cin >> c[i][j];

    ll minCost = INF;
    ll bestA = 0, bestB = 0;

    for (ll a = 0; a <= n; ++a) {
        for (ll b = 0; b <= m; ++b) {
            ll cost = 0;

            for (ll i = 0; i < n; ++i) {
                for (ll j = 0; j < m; ++j) {
                    double wiatrakX = i + 0.5;
                    double wiatrakY = j + 0.5;

                    double dx = 4.0 * (wiatrakX - a);
                    double dy = 4.0 * (wiatrakY - b);
                    ll d2 = round(dx * dx + dy * dy);

                    cost += c[i][j] * d2;
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