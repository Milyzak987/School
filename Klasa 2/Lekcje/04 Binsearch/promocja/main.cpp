#include <vector>

#include "cprolib.h"
using namespace std;

const int MAXN = 300007;

vector<pair<int, int>> people[MAXN];
int cities[MAXN];

int main() {
    int n, m, z;
    inicjuj(&n, &m, &z);

    for (int i = 1; i <= n; i++) {
        cities[i] = i;
        people[i].push_back(make_pair(0, i));
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        pobierz_promocje(i, &a, &b);

        int pa = cities[a];
        int pb = cities[b];

        int tmp = cities[a];
        cities[a] = cities[b];
        cities[b] = tmp;

        people[pa].push_back(make_pair(i, b));
        people[pb].push_back(make_pair(i, a));
    }

    for (int i = 0; i < z; i++) {
        int a, b;
        pobierz_zapytanie(&a, &b);
        int res = -1;
        for (const auto& promo : people[a]) {
            if (promo.first > b) {
                break;
            }
            res = promo.second;
        }
        odpowiedz(res);
    }
}
