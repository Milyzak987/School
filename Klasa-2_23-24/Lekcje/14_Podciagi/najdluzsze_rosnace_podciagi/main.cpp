#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 7;
const int R = (1 << 19);

vector<int> in(MAXN);
vector<pair<int, int>> insort(MAXN);
vector<pair<int, int>> dp(MAXN);
vector<pair<int, int>> tree(2 * R);
int MOD;

pair<int, int> maxpair(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    a.second = (a.second + b.second) % MOD;
    return a;
}

void set(int ind, pair<int, int> val) {
    ind += R;
    tree[ind] = maxpair(tree[ind], val);
    while (ind > 1) {
        ind /= 2;
        tree[ind] = maxpair(tree[2 * ind], tree[2 * ind + 1]);
    }
}

pair<int, int> maxx(int b) {
    int a = R;
    b += R;
    pair<int, int> res = maxpair(tree[a], tree[b]);
    while (a / 2 != b / 2) {
        if (a % 2 == 0) {
            res = maxpair(res, tree[a + 1]);
        }
        if (b % 2 == 1) {
            res = maxpair(res, tree[b - 1]);
        }
        a /= 2;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n >> MOD;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        insort[i] = {a, i};
    }

    sort(insort.begin(), insort.begin() + n);

    in[insort[0].second] = 1;
    int ind = 1;
    for (int i = 1; i < n; i++) {
        if (insort[i].first != insort[i - 1].first) {
            ind++;
        }
        in[insort[i].second] = ind;
    }

    int len = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = maxx(in[i] - 1);
        dp[i].first++;
        dp[i].second = dp[i].second == 0 ? 1 : dp[i].second;
        len = max(len, dp[i].first);
        set(in[i], dp[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i].first == len) {
            res = (res + dp[i].second) % MOD;
        }
    }
    cout << res;

    return 0;
}
