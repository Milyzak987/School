#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = M_PI;
const ld EPS = 1e-11L;

ld nor(ld kat) {
    kat = fmod(kat, 2.0L * PI);
    if (kat < 0) kat += 2.0L * PI;
    return kat;
}

struct prz {
    ld L, R;
    bool zawija;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ld R;
    cin >> n >> R;

    vector<ld> pocz_przedzialu;
    vector<prz> przedzialy;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;

        ld dist_sq = (ld)x * x + (ld)y * y;
        ld dist = sqrt(dist_sq);

        ld kat_srodek = atan2((ld)y, (ld)x);

        ld kat_styczna = 0.0;

        kat_styczna = acos(R / dist);

        ld s = nor(kat_srodek - kat_styczna);
        ld e = nor(kat_srodek + kat_styczna);

        pocz_przedzialu.push_back(s);

        bool zawija = (s > e);
        przedzialy.push_back({s, e, zawija});
    }

    sort(pocz_przedzialu.begin(), pocz_przedzialu.end());

    ll wyn = 0;

    for (const auto prz : przedzialy) {
        ll ile = 0;

        if (!prz.zawija) {
            auto it_start = lower_bound(pocz_przedzialu.begin(), pocz_przedzialu.end(), prz.L - EPS);
            auto it_end = upper_bound(pocz_przedzialu.begin(), pocz_przedzialu.end(), prz.R + EPS);
            ile = distance(it_start, it_end);
        } else {
            auto it_start = lower_bound(pocz_przedzialu.begin(), pocz_przedzialu.end(), prz.L - EPS);
            ile += distance(it_start, pocz_przedzialu.end());

            auto it_end = upper_bound(pocz_przedzialu.begin(), pocz_przedzialu.end(), prz.R + EPS);
            ile += distance(pocz_przedzialu.begin(), it_end);
        }

        wyn += ile;
    }

    cout << wyn - n << "\n";

    return 0;
}
