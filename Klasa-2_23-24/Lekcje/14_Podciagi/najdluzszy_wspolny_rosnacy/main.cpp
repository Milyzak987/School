#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2007;

vector<int> in1(MAX);
vector<int> in2(MAX);
int dp[MAX][MAX];
pair<int, int> org[MAX][MAX];
vector<int> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> in1[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> in2[i];
    }

    for (int i = 1; i <= n; i++) {
        int cur = 0;
        pair<int, int> cur_org = {0, 0};
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            org[i][j] = org[i - 1][j];
            if (in1[i] == in2[j] && cur + 1 > dp[i][j]) {
                dp[i][j] = cur + 1;
                org[i][j] = cur_org;
            }
            if (in1[i] > in2[j] && dp[i][j] > cur) {
                cur = dp[i][j];
                cur_org = {i, j};
            }
        }
    }

    int length = 0, poz = 0;
    pair<int, int> cur = {0, 0};
    for (int i = 1; i <= m; i++) {
        if (dp[n][i] > length) {
            length = dp[n][i];
            cur = org[n][i];
            poz = i;
        }
    }
    cout << length << "\n";
    res.push_back(in2[poz]);
    while (cur.second != 0) {
        res.push_back(in2[cur.second]);
        cur = org[cur.first][cur.second];
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }

    return 0;
}