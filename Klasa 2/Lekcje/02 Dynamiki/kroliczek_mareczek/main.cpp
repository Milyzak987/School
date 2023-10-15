#include <iostream>

using namespace std;

long long arr[1000002], dp[1000002];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n + 1; i++) {
        cin >> arr[i];
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    cout << dp[n + 1];
}