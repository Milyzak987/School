#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Opponent {
    vector<ll> skills;
    vector<ll> gains;
};

const int MAXN = 1e6 + 7;
vector<Opponent> opponents;
vector<ll> current_skills(MAXN, 0);

bool can_defeat(const vector<ll> &current_skills, const Opponent &opponent, ll k) {
    for (ll j = 0; j < k; j++) {
        if (current_skills[j] < opponent.skills[j])
            return false;
    }
    return true;
}

bool compare(const Opponent &a, const Opponent &b) {
    return *max_element(a.skills.begin(), a.skills.end()) <
           *max_element(b.skills.begin(), b.skills.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    opponents.resize(n);

    for (ll i = 0; i < n; i++) {
        opponents[i].skills.resize(k);
        for (ll j = 0; j < k; j++) {
            cin >> opponents[i].skills[j];
        }
    }

    for (ll i = 0; i < n; i++) {
        opponents[i].gains.resize(k);
        for (ll j = 0; j < k; j++) {
            cin >> opponents[i].gains[j];
        }
    }

    sort(opponents.begin(), opponents.end(), compare);

    ll defeated = 0;

    for (const auto &opponent : opponents) {
        if (can_defeat(current_skills, opponent, k)) {
            for (ll j = 0; j < k; j++) {
                current_skills[j] += opponent.gains[j];
            }
            defeated++;
        }
    }

    cout << defeated;
    return 0;
}