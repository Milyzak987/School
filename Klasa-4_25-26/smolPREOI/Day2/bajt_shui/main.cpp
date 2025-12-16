#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e7 + 7;
const int MAXN = 2e5 + 7;
const int MAXK = 22;
const int INF = 1e9;

vector<int> min_prime(MAXV);
vector<int> a(MAXN);

int cnt[MAXV];
int L[MAXN][MAXK];
int dp[MAXN][MAXK];

void sieve() {
    for (int i = 2; i * i < MAXV; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i * i; j < MAXV; j += i) {
                if (min_prime[j] == 0) min_prime[j] = i;
            }
        }
    }
    for (int i = 2; i < MAXV; ++i) {
        if (min_prime[i] == 0) min_prime[i] = i;
    }
}

int get_core(int val) {
    int core = 1;
    while (val > 1) {
        int p = min_prime[val];
        int count = 0;
        while (val % p == 0) {
            val /= p;
            count++;
        }
        if (count % 2 == 1) core *= p;
    }
    return core;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        int w;
        cin >> w;
        a[i] = get_core(w);
    }

    for (int c = 0; c <= k; ++c) {
        int l = 1;
        int unique_count = 0;

        for (int r = 1; r <= n; ++r) {
            if (cnt[a[r]] == 0) unique_count++;
            cnt[a[r]]++;

            while ((r - l + 1) - unique_count > c) {
                cnt[a[l]]--;
                if (cnt[a[l]] == 0) unique_count--;
                l++;
            }
            L[r][c] = l;
        }

        for (int i = l; i <= n; ++i) {
            if (cnt[a[i]] > 0) cnt[a[i]]--;
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int cost = 0; cost <= j; ++cost) {
                int start = L[i][cost];
                int prev_cost = j - cost;

                if (dp[start - 1][prev_cost] != INF) {
                    dp[i][j] = min(dp[i][j], dp[start - 1][prev_cost] + 1);
                }
            }
        }
    }

    int res = INF;
    for (int j = 0; j <= k; ++j) {
        res = min(res, dp[n][j]);
    }

    cout << res << "\n";
    return 0;
}