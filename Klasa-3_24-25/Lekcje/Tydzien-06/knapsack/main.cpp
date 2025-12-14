#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int MAXN = 5007;
const int MAXW = 10007;

vector<Pair> items(MAXN);
vector<ll> dp(MAXW, 0);
vector<ll> prefix(MAXN, 0), suffix(MAXN, 0);
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w, k;
    cin >> n >> w >> k;

    for (int i = 1; i <= n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    sort(items.begin() + 1, items.begin() + 1 + n);

    for (int i = n; i >= 1; i--) {
        suffix[i] = suffix[i + 1] + items[i].second;
        minHeap.push(items[i].second);
        if (minHeap.size() > k) {
            suffix[i] -= minHeap.top();
            minHeap.pop();
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w; j >= 0; j--) {
            if (j + items[i].first <= w) {
                dp[j + items[i].first] = max(dp[j + items[i].first], dp[j] + items[i].second);
            }
        }
        prefix[i] = dp[w];
    }

    ll result = 0;
    for (int i = 0; i <= n; i++) {
        result = max(result, prefix[i] + suffix[i + 1]);
    }
    cout << result;

    return 0;
}
