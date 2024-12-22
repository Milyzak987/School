#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int P = 353879;
const long long MOD = 1e9 + 9;
const int MAXN = 1e6 + 7;

long long poww[MAXN];
long long pref[MAXN];

long long charr(char c) {
    return c - 'a' + 1;
}

int hashPref(int L, int R) {
    R += 1;
    L += 1;
    return (pref[R] - ((pref[L - 1] * poww[R - L + 1]) % MOD) + MOD) % MOD;
}

bool check(int n, int m, int hash) {
    for (int i = 1; i < n - m; i++) {
        if (hashPref(i, i + m - 1) == hash) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long cur = 1;
    for (int i = 0; i <= MAXN; i++) {
        poww[i] = cur;
        cur = (cur * P) % MOD;
    }

    int n;
    string in;
    cin >> n >> in;

    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] * P + charr(in[i - 1])) % MOD;
    }

    vector<pair<int, int>> kandy;
    kandy.push_back(make_pair(0, 0));
    for (int i = 0; i < n - 1; i++) {
        if (hashPref(0, i) == hashPref(n - i - 1, n - 1)) {
            kandy.push_back(make_pair(i + 1, hashPref(0, i)));
        }
    }

    int l = 0, r = kandy.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (kandy[mid].first == 0) {
            cout << 0;
            return 0;
        }
        if (check(n, kandy[mid].first, kandy[mid].second)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << kandy[l].first;

    return 0;
}