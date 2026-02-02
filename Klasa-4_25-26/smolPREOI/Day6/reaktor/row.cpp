#include <bits/stdc++.h>

#include "rowlib.h"
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 7;
const ll MAXV = 1e18;
vector<ll> v(MAXN);

ll subtask1(int n) {
    int l = 0, r = n - 1;
    ll s = 0, e = MAXV;
    while (l <= r) {
        ll minn, maxx;
        ZapytajChrisa(s, e, minn, maxx);
        if (minn == -1) break;
        v[l] = minn;
        v[r] = maxx;
        s = minn + 1;
        e = maxx - 1;
        l++;
        r--;
    }
    ll res = 0;
    for (int i = 0; i < n - 1; i++) {
        ll diff = v[i + 1] - v[i];
        if (diff > res) {
            res = diff;
        }
    }
    return res;
}

ll subtask2(int n) {
    ll minn, maxx;
    ZapytajChrisa(0ll, MAXV, minn, maxx);

    ll diff = maxx - minn;
    ll range = (diff + n - 2) / (n - 1);  // ceil(diff / (n - 1))

    ll res = range;
    ll lastmx = minn;
    ll curr = minn + 1;

    while (curr < maxx) {
        ll s = curr;
        ll e = s + range - 1;

        if (e >= maxx) {
            e = maxx - 1;
        }
        if (s <= e) {
            ll mn, mx;
            ZapytajChrisa(s, e, mn, mx);

            if (mn != -1) {
                res = max(res, mn - lastmx);
                lastmx = mx;
            }
        }

        curr = e + 1;
    }

    res = max(res, maxx - lastmx);

    return res;
}

ll ZnajdzSkarpe(int T, int N) {
    if (T == 1) {
        return subtask1(N);
    } else {
        return subtask2(N);
    }
}
