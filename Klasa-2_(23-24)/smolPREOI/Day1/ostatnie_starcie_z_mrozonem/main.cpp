#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200007;
vector<long long> arr(MAXN);
int n, k;


bool check(long long ans, long long x) {
    long long left = 0, right = n;
    if (x < arr[0]) return true;

    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (arr[mid] <= x)
            left = mid;
        else
            right = mid - 1;
    }

    return (x - left - 1 >= ans);
}

long long binsearch(long long ans) {
    long long left = max(1LL, ans - n), right = arr[n - 1];

    while (left < right) {
        long long mid = (left + right) / 2;
        if (check(ans, mid))
            right = mid;
        else
            left = mid + 1;
    }
    return (left >= arr[n - 1]) ? ans + n : left;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        for (int j = 0; j < n; j++) cin >> arr[j];

        long long ans = 1;
        for (int j = 0; j < k; j++) ans = binsearch(ans);

        cout << ans << "\n";
    }
    return 0;
}