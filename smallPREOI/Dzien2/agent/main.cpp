#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid(20, vector<int>(20));

int countPaths(int n, int m, int k) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the starting point
    dp[0][0] = (grid[0][0] == k) ? 1 : 0;

    // Fill DP array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            // Check if current cell satisfies the condition
            if (i != 0 || j != 0) {
                dp[i][j] = (dp[i][j] * 1LL * (grid[i][j] == k)) % MOD;
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int paths = countPaths(n, m, k);
    cout << paths;

    return 0;
}
