#include <iostream>
#include <vector>
using namespace std;

struct q {
    vector<long long> add;
    long long or_add = 0;
    vector<pair<long long, long long>> del;

    void push(long long e) {
        add.push_back(e);
        or_add |= e;
    }

    void move_add() {
        while (!add.empty()) {
            long long e = add.back();
            add.pop_back();

            del.push_back({e, e | (del.empty() ? 0 : del.back().second)});
        }
        or_add = 0;
    }

    bool pop() {
        if (del.empty())
            move_add();
        if (del.empty())
            return false;
        del.pop_back();
        return true;
    }

    long long get() { return or_add | (del.empty() ? 0 : del.back().second); }

    void clear() {
        add.clear();
        del.clear();
        or_add = 0;
    }
};

const int MAXN = 2e6 + 7;
const int INF = 2e9;
long long inp[MAXN];
long long r[MAXN];
long long l[MAXN];
q que;

long long idx(long long x, int m) {
    if (x > m)
        return x % m;
    if (x <= 0)
        return m + x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long or_all = 0;

    for (int i = 1; i <= m; i++) {
        long long x;
        cin >> x;
        inp[i] = x | ((((1 << n) - 1) ^ x) << n);

        or_all |= inp[i];
    }

    int s = 1;
    que.push(inp[s]);
    for (int e = 1; e <= m; e++) {
        while (s < e || que.get() != or_all) {
            s++;
            que.push(inp[idx(s, m)]);
        }

        if (que.get() == or_all) {
            r[e] = s - e + 1;
        } else {
            r[e] = INF;
        }

        que.pop();
    }
    que.clear();

    s = m;
    que.push(inp[s]);
    for (int e = m; e >= 1; e--) {
        while (s > e || que.get() != or_all) {
            s--;
            que.push(inp[idx(s, m)]);
        }

        if (que.get() == or_all) {
            l[e] = e - s + 1;
        } else {
            l[e] = INF;
        }
        que.pop();
    }

    long long res = 0;
    for (int i = 1; i <= m; i++) {
        if (l[i] + r[idx(i + 1, m)] > m)
            continue;
        res += m - l[i] - r[idx(i + 1, m)] + 1;
    }
    cout << res / 2;
}