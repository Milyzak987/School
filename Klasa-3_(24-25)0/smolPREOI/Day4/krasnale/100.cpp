#include "kralib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 7;
int diffrences[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = init();
    vector<int> ans(n);

    int dif = n - 1, mini = 0;
    while (dif == n - 1) {
        mini++;
        dif = RoznicaCzapek(mini, n - 1);
        diffrences[mini, n - 1] = dif;
    }
    mini--;
    ans[mini] = 0;

    int dif1, dif2;
    // if (maxi < n - 1) {
    //     ans[maxi + 1] = n - 1 - RoznicaCzapek(maxi, maxi + 1);
    // }
    // for (int i = maxi + 2; i < n; i++) {
    //     // cout << "PYTANIE: " << maxi << " " << i << "\n";
    //     dif1 = RoznicaCzapek(i - 1, i);
    //     dif2 = RoznicaCzapek(i - 2, i);
    //     // cout << ans[i - 1] + dif1 << " ? " << ans[i - 2] - dif2 << "\n";
    //     if (ans[i - 1] + dif1 == ans[i - 2] + dif2 || dif2 == ans[i - 2] - ans[i - 1]) {
    //         ans[i] = ans[i - 1] + dif1;
    //     } else {
    //         ans[i] = ans[i - 1] - dif1;
    //     }
    // }

    // cout << "\n"<< mini << "\n";

    if (mini > 0) {
        ans[mini - 1] = RoznicaCzapek(mini - 1, mini);
    }

    int prev = ans[mini - 1], minx, minxi = mini;
    for (int i = mini - 2; i >= 0; i--) {
        dif = RoznicaCzapek(i, minxi);
        // cout << "PYTANIE: " << maxi << " " << i << "\n";
        if (dif == prev) {
            dif1 = RoznicaCzapek(i, i + 1);
            dif2 = RoznicaCzapek(i, i + 2);
            // cout << ans[i - 1] + dif1 << " ? " << ans[i - 2] - dif2 << "\n";
            if (ans[i + 1] + dif1 == ans[i + 2] + dif2 || dif2 == ans[i + 2] - ans[i + 1]) {
                ans[i] = ans[i + 1] + dif1;
            } else {
                ans[i] = ans[i + 1] - dif1;
            }
        } else {
            ans[i] = minx - dif;
        minx = ans[i];
        minxi = i;
        }
        prev = dif;
    }

    ans[mini + 1] = RoznicaCzapek(mini, mini + 1);
    prev = ans[mini + 1];
    minx = mini;
    for (int i = mini + 2; i < n; i++) {
        // cout << "PYTANIE: " << maxi << " " << i << "\n";
        dif = RoznicaCzapek(minxi, i);
        if (dif == prev) {
            dif1 = RoznicaCzapek(i - 1, i);
            dif2 = RoznicaCzapek(i - 2, i);
            // cout << ans[i - 1] + dif1 << " ? " << ans[i - 2] - dif2 << "\n";
            if (ans[i - 1] + dif1 == ans[i - 2] + dif2 || dif2 == ans[i - 2] - ans[i - 1]) {
                ans[i] = ans[i - 1] + dif1;
            } else {
                ans[i] = ans[i - 1] - dif1;
            }
        } else {
            ans[i] = minx - dif;
        minx = ans[i];
        minxi = i;
        }
        prev = dif;
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    Odpowiedz(ans);

    return 0;
}