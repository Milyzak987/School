#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

struct problem {
    ll dif, satLoss;
};

const ll MAXN = 2e5 + 7;
const ll MAXM = 1e6 + 7;
ll dificulties[MAXM];
problem problems[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll d, p;
    cin >> d >> p;

    for(ll i = 0; i < MAXM; i++){
        dificulties[i] = 0;
    }

    for (ll i = 0; i < d; i++) {
        ll a, b;
        cin >> a >> b;
        dificulties[a] = max(dificulties[a], b);
    }
    for (ll i = 0; i < p; i++) {
        cin >> problems[i].dif >> problems[i].satLoss;
    }

    ll curSat = 0;
    for(ll i = 0; i < MAXM; i++){
        curSat = max(curSat, dificulties[i]);
        dificulties[i] = curSat;
    }

    ll res = 0;
    for(ll i = 0; i < p; i++){
        res += max(0ll, dificulties[problems[i].dif] - problems[i].satLoss);
    }

    cout << res;
}