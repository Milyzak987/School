#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const ll MAXN = 2e5 + 7;
ll machine_order[MAXN];
ll last_used[MAXN];
ll results[MAXN];
ll queries[MAXN];
Pair tasks[MAXN];

void solve(ll n, ll m, ll q) {
    ll total_days = 0;

    for (ll i = 0; i < m; ++i) {
        for (ll j = tasks[i].first; j <= tasks[i].second; ++j) {
            machine_order[total_days++] = j;
        }
    }

    for (ll qi = 0; qi < q; ++qi) {
        ll s = queries[qi];

        memset(last_used, -1, sizeof(last_used));

        ll inspection_count = 0;

        for (ll day = 0; day < total_days; ++day) {
            ll machine = machine_order[day];
            if (last_used[machine] != -1 && day - last_used[machine] > s) {
                ++inspection_count;
            }
            last_used[machine] = day;
        }

        results[qi] = inspection_count;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    for (ll i = 0; i < m; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    for (ll i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    solve(n, m, q);

    for (ll i = 0; i < q; ++i) {
        cout << results[i] << " ";
    }

    return 0;
}