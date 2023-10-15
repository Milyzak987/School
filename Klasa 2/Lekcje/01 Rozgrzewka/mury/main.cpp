#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> wall_lengths(n);
    for (int i = 0; i < n; ++i) {
        cin >> wall_lengths[i];
    }

    vector<int> south, north;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            south.push_back(wall_lengths[i]);
        } else {
            north.push_back(wall_lengths[i]);
        }
    }

    sort(south.begin(), south.end());
    sort(north.begin(), north.end());

    int res = n;
    int count = 0;

    for (int i = 1; i <= h; ++i) {
        int south_count = south.size() - (lower_bound(south.begin(), south.end(), i) - south.begin());
        int north_count = north.size() - (upper_bound(north.begin(), north.end(), h - i) - north.begin());

        int total = south_count + north_count;
        if (total < res) {
            res = total;
            count = 1;
        } else if (total == res) {
            count++;
        }
    }

    cout << res << " " << count << endl;

    return 0;
}