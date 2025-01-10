#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int MAXN = 5007;

vector<int> input(MAXN);
vector<ll> prefix(MAXN, 0);
vector<vector<ll>> dp(MAXN, vector<ll>(MAXN, 0));

ll pref(int left, int right) {
    return prefix[right] - prefix[left - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
        prefix[i] = prefix[i - 1] + input[i];
    }

    for (int left = n; left >= 1; left--) {
        for (int right = left; right <= n; right++) {
            if (left == right) {
                dp[left][right] = input[left];
            } else {
                dp[left][right] = max(
                    input[left] + pref(left + 1, right) - dp[left + 1][right],
                    input[right] + pref(left, right - 1) - dp[left][right - 1]
                );
            }
        }
    }

    cout << dp[1][n];

    return 0;
}
