#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1002;
vector<vector<int>> board(MAXN, vector<int>(MAXN)), dp(MAXN, vector<int>(MAXN));

bool f(int num, int n) {
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= n; ++x) {
            dp[y][x] = max(dp[y][x - 1], dp[y - 1][x]) + (board[y][x] >= num);
        }
    }
    return dp[n][n] >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (f(mid, n)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l - 1;
    return 0;
}
