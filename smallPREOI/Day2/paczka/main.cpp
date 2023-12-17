#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence(200007);

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    long long maxSum = sequence[0];
    long long currentSum = sequence[0];

    for (int i = 1; i < n; i++) {
        if ((sequence[i] % 2 == 0 && sequence[i-1] % 2 != 0) || (sequence[i] % 2 != 0 && sequence[i-1] % 2 == 0)) {
            currentSum = max((long long)sequence[i], currentSum + sequence[i]);
            maxSum = max(maxSum, currentSum);
        } else {
            currentSum = sequence[i];
            maxSum = max(maxSum, currentSum);
        }
    }

    cout << maxSum << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();

    return 0;
}
