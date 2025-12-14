#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e7 + 7;
const int MAXN = 2e5 + 7;
const int INF = 1e9;

vector<int> min_prime(MAXV);
vector<int> a(MAXN);
vector<vector<int>> reach(22, vector<int>(MAXN));
map<int, bool> visited;

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

    vector<int> coords = a;

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin();
    }

    vector<int> freq(n + 1, 0);

    for (int c = 0; c <= k; c++) {
        int r = 0;
        int dist = 0;
        int current_cost = 0;

        fill(freq.begin(), freq.end(), 0);

        for (int l = 0; l < n; l++) {
            while (r < n) {
                int num = a[r];
                int is_new = (freq[num] == 0);

                int nlen = (r - l + 1);
                int ndist = dist + is_new;
                int cost = nlen - ndist;

                if (cost > c) {
                    break;
                }

                if (freq[num] == 0) dist++;
                freq[num]++;
                r++;
            }

            reach[c][l] = r;

            freq[a[l]]--;
            if (freq[a[l]] == 0) dist--;
        }
    }

    vector<int> dp(k + 1, 0);

    for (int p = 1; p <= n; p++) {
        vector<int> dp2(k + 1, 0);
        bool fin = false;

        for (int c = 0; c <= k; c++) {
            int breach = 0;

            for (int seg_c = 0; seg_c <= c; seg_c++) {
                int prev_c = c - seg_c;

                int st = dp[prev_c];

                if (st >= n) {
                    breach = n;
                    break;
                }

                int en = reach[seg_c][st];

                if (en > breach) {
                    breach = en;
                }
            }

            dp2[c] = breach;
            if (dp2[c] == n) fin = true;
        }

        dp = dp2;
        if (fin) {
            cout << p + 1;
            return 0;
        }
    }

    return 0;
}