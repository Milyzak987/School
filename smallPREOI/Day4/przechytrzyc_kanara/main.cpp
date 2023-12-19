#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 507;

vector<vector<int>> board(MAXN, vector<int>(MAXN, 0));

int shortestPath(pair<int, int> start, pair<int, int> end) {
    int res = abs(start.first - end.first) + abs(start.second - end.second);
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    if (shortestPath(start, end) <= k)
        cout << "TRIV";
    else
        cout << 1;

    return 0;
}