#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2007;
int matrix[MAXN][MAXN];
int heights[MAXN];

int area(int n) {
    int h, cur, res = 0;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && heights[dq.back()] >= heights[i]) {
            h = dq.back();
            dq.pop_back();

            int width = dq.empty() ? i : i - dq.back() - 1;
            int q = heights[h] * width;
            res = max(res, q);
        }
        dq.push_back(i);
    }

    while (!dq.empty()) {
        h = dq.back();
        dq.pop_back();
        cur = heights[h] * (dq.empty() ? n : n - dq.back() - 1);
        res = max(res, cur);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }
        ans = max(ans, area(n));
    }

    cout << ans;
}