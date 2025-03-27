#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXNN = 1e6 + 7;
const ll MAXN = 107;
ll skills[MAXN][MAXN];
ll gains[MAXN][MAXN];
bool defeated[MAXN];
vector<ll> current_skills(MAXN, 0);

ll kskill[MAXN];
ll kgain[MAXN];

bool can_defeat(ll idx, ll k) {
    for (ll j = 0; j < k; j++) {
        if (current_skills[j] < skills[idx][j])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    if (n == 1) {
        ll res = 1;
        for (ll i = 0; i < k; i++) {
            ll a;
            cin >> a;
            if (a != 0) {
                res = 0;
            }
        }
        for (ll i = 0; i < k; i++) {
            ll t;
            cin >> t;
        }
        cout << res;
        return 0;
    }
    if (k == 1) {
        ll cur = 0;
        for (ll i = 0; i < n; i++) {
            cin >> kskill[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> kgain[i];
        }
        sort(kskill, kskill + n);
        for (ll i = 0; i < n; i++) {
            if (cur < kskill[i]) {
                cout << i;
                return 0;
            } else {
                cur += kgain[i];
            }
        }
        cout << n;
        return 0;
    }

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
            cin >> skills[i][j];

    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
            cin >> gains[i][j];

    ll defeated_count = 0;
    bool progress = true;

    while (progress) {
        progress = false;
        for (ll i = 0; i < n; i++) {
            if (!defeated[i] && can_defeat(i, k)) {
                for (ll j = 0; j < k; j++) {
                    current_skills[j] += gains[i][j];
                }
                defeated[i] = true;
                defeated_count++;
                progress = true;
            }
        }
    }

    cout << defeated_count;
    return 0;
}