#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 5e3 + 7;
vector<vector<int>> dp(MAXN, vector<int>(MAXN));

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

    int al = a.length();
    int bl = b.length();
	for (int i = 1; i <= al; i++) {
		for (int j = 1; j <= bl; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}

	cout << dp[al][bl] << "\n";

	string res;
	while (al >= 1 && bl >= 1) {
		if (dp[al][bl] == dp[al - 1][bl]) {
			al--;
		} else if (dp[al][bl] == dp[al][bl - 1]) {
			bl--;
		} else if (dp[al][bl] == dp[al - 1][bl - 1] + 1) {
			res += a[al - 1];
			al--;
			bl--;
		}
	}
    reverse(res.begin(),res.end());
    cout << res;

	return 0;
}