#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            
        }
    }

    dp[0][0] = (board[0][0] == 0) ? 1 : 0;
    for (int i = 1; i < n; i++) {
        if (board[i][0] == 0)
            dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        if (board[0][j] == 0)
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (board[i][j] == 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000;
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    return 0;
}