#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 7;
vector<int> a(MAXN);
vector<int> left_bound(MAXN);
vector<int> right_bound(MAXN);
vector<int> ans(MAXN, 0);

stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            left_bound[i] = -1;
        } else {
            left_bound[i] = s.top();
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            right_bound[i] = n;
        } else {
            right_bound[i] = s.top();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        int len = right_bound[i] - left_bound[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }

    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
}