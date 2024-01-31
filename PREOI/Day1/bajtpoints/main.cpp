#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> grid(507, vector<char>(507));
vector<vector<int>> grid2(507, vector<int>(507));

int countWays(int a, int b, int k, vector<vector<char>>& grid, int x, int y) {
    if (x < 0 || x >= a || y < 0 || y >= b || grid[x][y] == '#') {
        return 0;
    }

    if (k == 0) {
        return (x == 0 && y == 0) ? 1 : 0;
    }

    int ways = 0;

    ways += countWays(a, b, k - 1, grid, x + 1, y);
    ways += countWays(a, b, k - 1, grid, x - 1, y);
    ways += countWays(a, b, k - 1, grid, x, y + 1);
    ways += countWays(a, b, k - 1, grid, x, y - 1);

    return ways;
}

int main() {
    int a, b, k, j;
    cin >> a >> b >> k >> j;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (grid[i][j] == '#') {
                grid2[i][j] = -1;
            } else {
                grid2[i][j] = countWays(a, b, k, grid, i, j);
            }
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << grid2[i][j];
        }
        cout << "\n";
    }

    return 0;
}