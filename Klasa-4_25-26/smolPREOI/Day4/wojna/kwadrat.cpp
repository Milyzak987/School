#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0L);
const ld TWO_PI = 2.0L * PI;
const ld EPS = 1e-11L;

struct Kitten {
    ll x, y;
    ld angle;
    ld spread;
};

const int MAXN = 5e4 + 7;
vector<Kitten> kittens(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ld R;
    cin >> n >> R;

    bool podzad = true;

    for (int i = 0; i < n; ++i) {
        cin >> kittens[i].x >> kittens[i].y;

        ld dist = sqrt((ld)kittens[i].x * kittens[i].x + (ld)kittens[i].y * kittens[i].y);

        kittens[i].angle = atan2((ld)kittens[i].y, (ld)kittens[i].x);

        if (kittens[i].angle < 0) kittens[i].angle += TWO_PI;

        if (dist > R) {
            kittens[i].spread = acos(R / dist);
        } else {
            kittens[i].spread = 0.0L;
        }
        if (kittens[i].y != 0) {
            podzad = false;
        }
    }

    if (podzad) {
        int up = 0, down = 0;
        for (int i = 0; i < n; ++i) {
            if (kittens[i].x > 0) {
                up++;
            } else {
                down++;
            }
        }
        cout << (up * (up - 1)) / 2 + (down * (down - 1)) / 2 << "\n";
        return 0;
    }

    ll count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ld angle_diff = abs(kittens[i].angle - kittens[j].angle);

            if (angle_diff > PI) {
                angle_diff = TWO_PI - angle_diff;
            }

            if (angle_diff < (kittens[i].spread + kittens[j].spread - EPS)) {
                count++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
