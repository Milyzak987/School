#include <iostream>
#include <vector>
using namespace std;

unsigned long long grid[21][21], dp[21][21];
unsigned long long k, res = 0, curr = 0;
int n, m;

void solve(int i, int j) {
    if (i == n && j == m) {
        curr ^= grid[i][j];
        if (curr == k) res++;
        curr ^= grid[i][j];
        return;
    }
    if (i > n || j > m) return;
    curr ^= grid[i][j];

    if (i + 1 <= n) solve(i + 1, j);
    if (j + 1 <= m) solve(i, j + 1);

    curr ^= grid[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }
    
    solve(1, 1);
    cout << res;
    return 0;
}
