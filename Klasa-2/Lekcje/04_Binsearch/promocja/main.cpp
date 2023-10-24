#include <vector>
#include <algorithm>
#include "cprolib.h"

using namespace std;

const int MAXN = 300007;

vector<pair<int, int>> ppl[MAXN];
int cit[MAXN];

int main() {
    int n, m, z;
    inicjuj(&n, &m, &z);

    for (int i = 1; i <= n; i++) {
        cit[i] = i;
        ppl[i].push_back(make_pair(0, i));
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        pobierz_promocje(i, &a, &b);

        int pa = cit[a];
        int pb = cit[b];

        int tmp = cit[a];
        cit[a] = cit[b];
        cit[b] = tmp;

        ppl[pa].push_back(make_pair(i, b));
        ppl[pb].push_back(make_pair(i, a));
    }

    for (int i = 1; i <= n; i++) {
        sort(ppl[i].begin(), ppl[i].end());
    }

    for (int i = 0; i < z; i++) {
        int a, b;
        pobierz_zapytanie(&a, &b);
        int res = -1;

        int left = 0, right = ppl[a].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (ppl[a][mid].first <= b) {
                res = ppl[a][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        odpowiedz(res);
    }
}
