#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr(100002);
int n, t;

bool check(double x) {
    double total_time = 0;
    for (int i = 0; i < n; ++i) {
        double speed = arr[i].second + x;
        total_time += arr[i].first / speed;
    }
    return total_time <= t;
}

double binary_search(double left, double right) {
    while (right - left > 1e-7) {
        double mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    cout << fixed << setprecision(6) << binary_search(0, 1e9);

    return 0;
}