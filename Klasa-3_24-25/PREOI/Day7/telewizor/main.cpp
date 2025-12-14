#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> Pair;

const int MAXN = 1e6 + 7;
vector<Pair> events;
vector<int> freq(MAXN, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int day;
            cin >> day;
            events.emplace_back(day, i);
        }
    }

    sort(events.begin(), events.end());

    int count = 0;
    int min_len = INT_MAX;
    int left = 0;
    int T = n * m;

    for (int i = 0; i < T; ++i) {
        int film = events[i].second;
        if (freq[film] == 0) {
            ++count;
        }
        ++freq[film];

        while (count == n) {
            int current_len = events[i].first - events[left].first + 1;
            if (current_len < min_len) {
                min_len = current_len;
            }

            int left_film = events[left].second;
            --freq[left_film];
            if (freq[left_film] == 0) {
                --count;
            }
            ++left;
        }
    }

    cout << min_len;

    return 0;
}