#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void BFS(vector<vector<bool>>& grid, vector<vector<int>>& ans) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]) {
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        for (auto& dir : directions) {
            int x = current.first + dir[0];
            int y = current.second + dir[1];

            if (x >= 0 && x < n && y >= 0 && y < m && ans[x][y] == -1) {
                ans[x][y] = ans[current.first][current.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (input[j] == '1');
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, -1));

    BFS(grid, ans);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
