#include <bits/stdc++.h>

#include "kralib.h"
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 7;
int diffPairs[MAXN];
int diffThrees[MAXN];
int relations[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = init();
    vector<int> ans(n);

    for (int i = 0; i <= n - 2; i++) {
        diffPairs[i] = RoznicaCzapek(i, i + 1);
    }
    for (int i = 0; i <= n - 3; i++) {
        diffThrees[i] = RoznicaCzapek(i, i + 2);
    }

    relations[1] = -1;
    for (int i = 2; i <= n - 1; i++) {
        if (diffPairs[i - 2] + diffPairs[i - 1] == diffThrees[i - 2]) {
            relations[i] = relations[i - 1];
        } else {
            relations[i] = -relations[i - 1];
        }
    }

    int minx = 0, maxx = 0, mini = 0, maxi = 0;
    ans[0] = 0;
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] + relations[i] * diffPairs[i - 1];
        if (ans[i] < minx) {
            minx = ans[i];
            mini = i;
        }
        if (ans[i] > maxx) {
            maxx = ans[i];
            maxi = i;
        }
    }

    int znak = 1;
    if (mini > maxi) {
        swap(mini, maxi);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + -1 * relations[i] * diffPairs[i - 1];
        }
    }

    int offset = 0 - ans[mini];

    for (int i = 0; i < n; i++) {
        ans[i] += offset;
    }

    Odpowiedz(ans);

    return 0;
}
