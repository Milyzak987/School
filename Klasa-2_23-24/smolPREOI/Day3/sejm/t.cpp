#include <algorithm>
#include <vector>

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

    if (wywiad(1, n) == wywiad(2, n)) {
        pos1.push_back(1);
    } else {
        pos2.push_back(1);
    }

    for (auto u : pos) {
        if (u.first == num2) {
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