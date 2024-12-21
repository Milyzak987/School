#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

const ll MAXN = 1e6 + 7;
vector<int> cost1(MAXN);
vector<int> cost2(MAXN);
vector<int> schem(MAXN, INT_MAX);
vector<int> dp(MAXN);

void schematics(int n) {
    for (int i = 1; i <= n; i++) {
        schem[cost1[i]] = min(schem[cost1[i]], cost1[i] - cost2[i]);
    }
    for (int i = 1; i < MAXN; i++) {
        schem[i] = min(schem[i], schem[i - 1]);
    }
}

void computeDP() {
    for (int i = 1; i < MAXN; i++) {
        if (schem[i] != INT_MAX) {
            dp[i] = dp[max(0, i - schem[i])] + 2;
        }
    }
}

ll solve(int m) {
    ll result = 0;
    for (int i = 0; i < m; i++) {
        int mass;
        cin >> mass;

        while (mass > MAXN - 1) {
            int reduction = (mass - (MAXN - 1) - 1) / schem[MAXN - 1] + 1;
            mass -= reduction * schem[MAXN - 1];
            result += 2 * reduction;
        }
        result += dp[mass];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> cost1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cost2[i];
    }

    schematics(n);
    computeDP();

    cout << solve(m);
    return 0;
}