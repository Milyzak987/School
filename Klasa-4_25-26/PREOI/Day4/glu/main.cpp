#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_blocked(ll start, ll end, ll m, const set<ll>& blocked) {
    if (start == end) return false;

    if (start < end) {
        auto it = blocked.lower_bound(start);
        if (it != blocked.end() && *it < end) {
            return true;
        }
    } else {
        auto it = blocked.lower_bound(start);
        if (it != blocked.end()) {
            return true;
        }

        if (end > 0) {
            it = blocked.lower_bound(0);
            if (it != blocked.end() && *it < end) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll m;
    int q;

    cin >> n >> m >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<ll> blocked_roads;
    ll last_x = 0;

    for (int k = 0; k < q; ++k) {
        int type;
        cin >> type;

        if (type == 1) {
            ll y;
            cin >> y;
            ll r = (last_x + y) % m;

            if (blocked_roads.count(r)) {
                blocked_roads.erase(r);
            } else {
                blocked_roads.insert(r);
            }

        } else {
            ll y, z;
            cin >> y >> z;

            ll friend_a = (last_x + y) % n;
            ll friend_b = (last_x + z) % n;

            if (friend_a > friend_b) swap(friend_a, friend_b);

            ll total_time = 0;
            bool possible = true;

            for (int i = friend_a; i < friend_b; ++i) {
                ll u = a[i];
                ll v = a[i + 1];

                ll dist_cw = (v - u + m) % m;
                ll dist_ccw = (u - v + m) % m;

                bool cw_blocked = is_blocked(u, v, m, blocked_roads);

                bool ccw_blocked = is_blocked(v, u, m, blocked_roads);

                ll current_step_cost = -1;

                if (!cw_blocked && !ccw_blocked) {
                    current_step_cost = min(dist_cw, dist_ccw);
                } else if (!cw_blocked) {
                    current_step_cost = dist_cw;
                } else if (!ccw_blocked) {
                    current_step_cost = dist_ccw;
                } else {
                    possible = false;
                    break;
                }

                total_time += current_step_cost;
            }

            if (possible) {
                cout << total_time << "\n";
                last_x = total_time;
            } else {
                cout << "-1\n";
                last_x = -1;
            }
        }
    }

    return 0;
}