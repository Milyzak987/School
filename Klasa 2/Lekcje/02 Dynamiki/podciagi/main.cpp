#include <iostream>
#include <vector>
using namespace std;

int arr[500001];
int dp[500001];
int MOD = 1000000007;
vector<int> last(1000002);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        
        if (last[arr[i]] != 0) {
            dp[i] = (dp[i] - dp[last[arr[i]] - 1] + MOD) % MOD;
        }
        last[arr[i]] = i;
    }
    cout << dp[n];
    return 0;
}