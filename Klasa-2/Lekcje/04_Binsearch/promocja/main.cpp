#include <vector>

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

    for (int i = 0; i < z; i++) {
        int a, b;
        pobierz_zapytanie(&a, &b);
        int res = -1;
        for (auto prom : ppl[a]) {
            if (prom.first > b) {
                break;
            }
            res = prom.second;
        }
        odpowiedz(res);
    }
}