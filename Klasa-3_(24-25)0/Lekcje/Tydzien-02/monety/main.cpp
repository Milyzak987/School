#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 7;

vector<int> flips(MAXN);
vector<long long> pref(MAXN);
unordered_map<long long, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'R') {
            flips[i] = k;
        } else {
            flips[i] = -1;
        }
    }
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + flips[i];
        if (m[pref[i]] == 0) {
            m[pref[i]] = i;
        }
    }

    int res = 0;
    for (int i = n; i >= 1; i--) {
        if (pref[i] == 0) {
            res = max(res, i);
            continue;
        }
        int pop = m[pref[i]];
        res = (pop != 0 ? max(res, i - pop) : res);
    }
    cout << res;

    return 0;
}