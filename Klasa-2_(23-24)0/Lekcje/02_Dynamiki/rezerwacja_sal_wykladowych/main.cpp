#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sortbysec(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end(), sortbysec);

    vector<int> dp(n);
    dp[0] = intervals[0].second - intervals[0].first;

    for (int i = 1; i < n; i++) {
        int currentSize = intervals[i].second - intervals[i].first;
        dp[i] = currentSize;

        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (intervals[mid].second <= intervals[i].first) {
                dp[i] = max(dp[i], currentSize + dp[mid]);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}