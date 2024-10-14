#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 3e6 + 7;
vector<long long> st(MAXN);
vector<long long> en(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int d, s;
        cin >> d >> s;
        st[d] = s;
        en[d + s] += 1;
    }

    long long maxx = -1, maxi = -1, minx = 2e9, mini = -1;
    long long j = 0, str = 0;
    for (int i = 1; i <= m; i++) {
        str -= j;
        j -= en[i];
        if (st[i] > 0) {
            j++;
            str += st[i];
        }
        if (str > maxx) {
            maxx = str;
            maxi = i;
        }
        if (str < minx) {
            minx = str;
            mini = i;
        }
    }

    cout << maxi << " " << mini;
    return 0;
}