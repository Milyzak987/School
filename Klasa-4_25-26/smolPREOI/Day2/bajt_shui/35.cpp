// 35 points
#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e7 + 7;
const int MAXN = 2e5 + 7;
const int INF = 1e9;

vector<int> min_prime(MAXV);
vector<int> a(MAXN);
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

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[a[i]]) {
            res++;
            visited.clear();
        }
        visited[a[i]] = true;
    }
    cout << res + 1 << "\n";
    return 0;
}