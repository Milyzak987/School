#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 3e5 + 7;
vector<int> slot2(MAXN);
vector<int> slot3(MAXN);
vector<int> slot1(MAXN);
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        slot1[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        slot2[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        slot3[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        int a = (slot1[i] - slot2[i] + n) % n;
        int b = (slot1[i] - slot3[i] + n) % n;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int res = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            res = max(res, cur);
            cur = 0;
        }
        cur++;
    }

    cout << max(res, cur);
}