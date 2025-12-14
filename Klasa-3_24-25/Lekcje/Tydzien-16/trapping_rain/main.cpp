// #include <algorithm>
// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

// typedef long long ll;
// typedef pair<int, ll> pii;

// const int MAXN = 1e6 + 7;
// const ll INF = 1e18;

// ll a[MAXN];

// struct Zbior {
//     ll suma;
//     set<pii> zbior;

//     void clear(int n, int kier) {
//         zbior.clear();
//         if (kier == 1) {
//             zbior.insert({1, 0});
//             zbior.insert({n + 1, INF});
//         } else {
//             zbior.insert({-n, 0});
//             zbior.insert({0, INF});
//         }
//         suma = 0;
//     }

//     void dodaj(int i, ll wart) {
//         auto x = zbior.upper_bound({i, INF});
//         x--;

//         if (x->second >= wart) return;

//         suma -= x->second * (next(x)->first - i);
//         suma += wart * (next(x)->first - i);

//         if (x->first == i) {
//             zbior.erase(x);
//         }
//         x = zbior.insert({i, wart}).first;

//         while (next(x)->second <= wart) {
//             int ile = next(next(x))->first - next(x)->first;
//             suma -= next(x)->second * ile;
//             suma += wart * ile;
//             zbior.erase(next(x));
//         }
//     }
// };

// Zbior f, g;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         ll suma = 0, maks = 0;

//         f.clear(n, 1);
//         g.clear(n, -1);

//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//             suma += a[i];
//             maks = max(maks, a[i]);
//             f.dodaj(i, a[i]);
//             g.dodaj(-i, a[i]);
//         }

//         int q;
//         cin >> q;

//         while (q--) {
//             int x, y;
//             cin >> x >> y;

//             a[x] += y;
//             suma += y;
//             maks = max(maks, a[x]);

//             f.dodaj(x, a[x]);
//             g.dodaj(-x, a[x]);

//             cout << f.suma + g.suma - maks * n - suma << "\n";
//         }
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    cout << "Zrobione";
}