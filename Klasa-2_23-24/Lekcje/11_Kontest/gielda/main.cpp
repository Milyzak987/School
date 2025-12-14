#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e4 + 7;
const int MAXK = 2e3 + 7;
vector<int> prices(MAXN);
vector<vector<long long>> dp(MAXK, vector<long long>(MAXN));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int z = 2 * k;
    for (int i = 1; i <= z; i++) {
        if (i % 2 == 0) {
            dp[i][0] = dp[i - 1][0] + prices[0];
        } else {
            dp[i][0] = dp[i - 1][0] - prices[0];
        }
        for (int j = 2; j <= n; j++) {
            if (i % 2 == 1) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] - prices[j - 1]);
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j] + prices[j - 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= z; j++) {
            if (j % 2 == 1) {
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i] - prices[i - 1]);
            } else {
                dp[j][i] = max(dp[j][i - 1], dp[j - 1][i] + prices[i - 1]);
            }
        }
    }

    cout << dp[z][n];
}