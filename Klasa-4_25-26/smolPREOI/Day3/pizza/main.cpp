#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> para;

const int MAXN = 2e5 + 7;

vector<int> a(MAXN);
vector<int> counts(MAXN, 0);
vector<int> vals;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }

    int l = 0;
    int cur = 0;
    int res = 0;
    int lim = k + 1;

    for (int r = 0; r < n; ++r) {
        if (counts[a[r]] == 0) {
            cur++;
        }
        counts[a[r]]++;

        while (cur > lim) {
            counts[a[l]]--;
            if (counts[a[l]] == 0) {
                cur--;
            }
            l++;
        }

        if (counts[a[r]] > res) {
            res = counts[a[r]];
        }
    }

    cout << res << "\n";

    return 0;
}
