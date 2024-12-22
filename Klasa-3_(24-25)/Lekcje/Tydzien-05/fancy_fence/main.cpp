#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;
vector<pair<int, int>> rectangles(MAXN);
stack<pair<int, int>> s;

long long rec(int h, int w) {
    long long x = (((h + 1) * h) / 2) % MOD;
    long long y = (((w + 1) * w) / 2) % MOD;
    return (x * y) % MOD;
}

int mod(long long x) { return x % MOD; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].second;
    }

    long long res = 0, before = 0;
    for (int i = 1; i < n; i++) {
        int h = rectangles[i].first;
        int w = rectangles[i].second;
        while (!s.empty() && h < s.top().first) {
            before -= (s.top().first - h) * s.top().second;
            s.pop();
        }
        s.push({h, w});
        res = mod(res + rec(h, w));
        before += h * w;
        res = mod(res + mod(before * min(h, s.top().first) * w));
    }

    cout << res;

    return 0;
}