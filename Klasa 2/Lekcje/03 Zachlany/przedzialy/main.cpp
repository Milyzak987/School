#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool sortbysec(pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);
}

vector<pair<int, int>> intv(1000002);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> intv[i].first >> intv[i].second;
    }
    sort(intv.begin(), intv.begin() + n, sortbysec);

    int res = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (intv[i].first >= last) {
            last = intv[i].second;
            res++;
        }
    }
    cout << res;

    return 0;
}