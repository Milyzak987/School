#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 15e4 + 1;
vector<pair<int, int>> con(MAXN), imp(MAXN), luck(MAXN);
vector<int> con_us(MAXN), imp_us(MAXN), luck_us(MAXN);
vector<int> del(MAXN, false);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> con_us[i] >> imp_us[i] >> luck_us[i];
        con.push_back(make_pair(con_us[i], i));
        imp.push_back(make_pair(imp_us[i], i));
        luck.push_back(make_pair(luck_us[i], i));
    }

    sort(con.begin(), con.end(), greater<pair<int, int>>());
    sort(imp.begin(), imp.end(), greater<pair<int, int>>());
    sort(luck.begin(), luck.end(), greater<pair<int, int>>());

    int tc = 0, ti = 0, tl = 0;
    while (tc != n && ti != n && tl != n) {
        int maxc = con[tc].first, maxi = imp[ti].first, maxl = luck[tl].first;
        int ic = con[tc].second, ii = imp[ti].second, il = luck[tl].second;
        if (imp_us[ic] == maxi || luck_us[ic] == maxl) {
            del[con[tc].second] = true;
            tc++;
        } else if (con_us[ii] == maxc || luck_us[ii] == maxl) {
            del[imp[ti].second] = true;
            ti++;
        } else if (con_us[il] == maxc || imp_us[il] == maxi) {
            del[luck[tl].second] = true;
            tl++;
        } else {
            cout << maxc + maxi + maxl;
            return 0;
        }

        while (del[con[tc].second] && tc != n) {
            tc++;
        }
        while (del[imp[ti].second] && ti != n) {
            ti++;
        }
        while (del[luck[tl].second] && tl != n) {
            tl++;
        }
    }

    cout << -1;

    return 0;
}