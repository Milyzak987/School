#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAXN = 200007;
vector<int> numbers(MAXN), leftCount(MAXN), rightCount(MAXN);

void solve() {
    int n, k, b;
    cin >> n >> k;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < n; i++) cin >> b;

    sort(numbers.begin(), numbers.begin() + n);

    vector<int> leftCount(n), rightCount(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (numbers[i] - numbers[j] > k) {
            j++;
        }
        leftCount[i] = i - j + 1;
        if (i > 0) {
            leftCount[i] = max(leftCount[i], leftCount[i - 1]);
        }
    }
    j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (numbers[j] - numbers[i] > k) {
            j--;
        }
        rightCount[i] = j - i + 1;
        if (i + 1 < n) {
            rightCount[i] = max(rightCount[i], rightCount[i + 1]);
        }
    }

    int result = 1;
    for (int i = 0; i < n - 1; i++) {
        result = max(result, rightCount[i + 1] + leftCount[i]);
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}