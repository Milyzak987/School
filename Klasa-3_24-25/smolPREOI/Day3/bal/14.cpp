#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAXN = 2e5 + 7;
bool parametry[MAXN][20];
ll ceny[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, q;
    cin >> n >> k >> q;

    for (ll i = 1; i <= n; i++) {
        ll t;
        cin >> ceny[i] >> t;
        for (ll j = 0; j < t; j++) {
            ll x;
            cin >> x;
            parametry[i][x] = true;
        }
    }

    while (q--) {
        ll t;
        cin >> t;
        ll minx = 1e9 + 7, mini = -1;
        deque<ll> klientka;
        for (ll i = 0; i < t; i++) {
            ll x;
            cin >> x;
            klientka.push_back(x);
        }
        bool works = true;
        for (ll i = 1; i <= n; i++) {
            for(auto v : klientka){
                // cout << v << " ";
                if(!parametry[i][v]){
                    works = false;
                }
            }
            // cout << '\n';
            if(works){
                // cout << "WORKS\n";
                if(ceny[i] < minx){
                    minx = ceny[i];
                    mini = i;
                }
            }
            works = true;
        }
        if(mini == -1){
            cout << "NIE\n";
        } else {
            cout << mini << "\n";
        }
    }

}