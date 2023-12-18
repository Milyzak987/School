#include <vector>
#include <algorithm>

#include "sejlib.h"
using namespace std;

int main() {
    int i, num2;
    vector<int> pos1 = {}, pos2 = {};
    vector<pair<int, int>> pos = {};
    int n = init();

    num2 = wywiad(2, 1);
    pos.push_back({num2, 2});

    for (int i = 3; i <= n; ++i) {
        pos.push_back({wywiad(i, 1), i});
    }
    sort(pos.begin(), pos.end());

    int max_count = 1, good = pos[0].first, curr_count = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (pos[i].first == pos[i - 1].first)
            curr_count++;
        else
            curr_count = 1;
        if (curr_count > max_count) {
            max_count = curr_count;
            good = pos[i - 1].first;
        }
    }

    if (wywiad(1, n) == wywiad(2, n)) {
        if (num2 == good)
            pos1.push_back(1);
        else
            pos2.push_back(1);
    } else {
        if (num2 == good)
            pos2.push_back(1);
        else
            pos1.push_back(1);
    }

    for (auto u : pos) {
        if (u.first == good) {
            pos1.push_back(u.second);
        } else {
            pos2.push_back(u.second);
        }
    }

    if (pos1.size() < pos2.size()) {
        sort(pos1.begin(), pos1.end());
        odpowiedz(pos1);
    } else {
        sort(pos2.begin(), pos2.end());
        odpowiedz(pos2);
    }
}
