#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pair;

const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;

vector<Pair> rectangles(MAXN);
stack<Pair> s;

ll mod(ll x) { 
    return x % MOD; 
}

ll po2(ll x) { 
    return mod(x * (x - 1) / 2); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> rectangles[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> rectangles[i].second;
    }

    ll result = 0, before = 0;

    for (int i = 1; i <= n; i++) {
        ll h = rectangles[i].first;
        ll w = rectangles[i].second;

        result = mod(result + mod(po2(w + 1) * po2(h + 1)));

        ll combined_width = 0;
        while (!s.empty() && s.top().first > h) {
            before = mod(before - mod(po2(s.top().first + 1) * mod(s.top().second)) + MOD);
            combined_width += s.top().second;
            s.pop();
        }
        if (combined_width > 0) {
            before = mod(before + mod(po2(h + 1) * mod(combined_width)));
            s.push({h, combined_width});
        }

        result = mod(result + mod(before * mod(w)));
        before = mod(before + mod(po2(h + 1) * mod(w)));

        s.push({h, w});
    }

    cout << result;

    return 0;
}
