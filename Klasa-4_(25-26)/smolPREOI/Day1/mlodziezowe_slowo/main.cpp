#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    char c_max = 'a';
    for (; c_max <= 'z'; ++c_max) {
        int last_reachable = -1;
        bool possible = true;

        for (int i = 0; i < n; ++i) {
            if (s[i] <= c_max) {
                if (i - last_reachable <= m) {
                    last_reachable = i;
                }
            }

            if (i == last_reachable + m) {
                possible = false;
                break;
            }
        }

        if (possible && last_reachable >= n - m) {
            break;
        }
    }

    vector<int> small_indices;
    vector<int> large_indices;
    for (int i = 0; i < n; ++i) {
        if (s[i] < c_max) {
            small_indices.push_back(i);
        } else if (s[i] == c_max) {
            large_indices.push_back(i);
        }
    }

    string result = "";
    int pos = -1;

    auto bridge = [&](int target) {
        while (target - pos > m) {
            auto it = upper_bound(large_indices.begin(), large_indices.end(), pos + m);

            --it;

            pos = *it;
            result += c_max;
        }
    };

    for (int idx : small_indices) {
        bridge(idx);
        pos = idx;
        result += s[idx];
    }

    while (pos < n - m) {
        auto it = upper_bound(large_indices.begin(), large_indices.end(), pos + m);
        --it;
        pos = *it;
        result += c_max;
    }

    sort(result.begin(), result.end());
    cout << result << '\n';

    return 0;
}