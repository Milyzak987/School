#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int wid, len, input, res = 0, xm = 1, ym = 1;
    vector<pair<int, int>> costs;

    cin >> wid >> len;
    for (int i = 0; i < wid - 1; i++) {
        cin >> input;
        costs.push_back(make_pair(input, 0));
    }

    for (int i = 0; i < len - 1; i++) {
        cin >> input;
        costs.push_back(make_pair(input, 1));
    }

    sort(costs.begin(), costs.end(), greater());

    for (int i = 0; i < wid + len - 2; i++) {
        if (costs[i].second==0) {
            res += costs[i].first * xm;
            ym++;
        } else {
            res += costs[i].first * ym;
            xm++;
        }
    }
    cout << res;
    return 0;
}