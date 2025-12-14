#include "loc_lib.h"
#include <bits/stdc++.h>
using namespace std;
#define rep(i, p, k) for (int i(p); i < (k); ++i)
namespace {
int in() {
    static int x;
    cin >> x;
    return x;
}
int n, z, l = 0, N;
vector<int> ar;
void init() {
    static bool juz(0);
    if (juz)
        return;
    juz = 1;
    n = in();
    N = 1 << n;
    ar.resize(N + 1);
    rep(i, 0, N - 2)++ ar[in()];
    ++ar[z = in()];
}
} // namespace
int daj_n() {
    init();
    return n;
}
char pytanie(int a, int b) {
    init();
    if (a < 1 || a > N || b < 1 || b > N || a == b) {
        cout << "NIEPOPRAWNE PYTANIE " << a << ' ' << b << '\n';
        exit(0);
    }
    ++l;
    if (ar[a] < ar[b])
        return '<';
    if (ar[a] == ar[b])
        return '=';
    if (ar[a] > ar[b])
        return '>';
    return ' ';
}
void odpowiedz(int r) {
    init();
    if (r != z) {
        cout << "NIEPOPRAWNA ODPOWIEDZ " << r << "!=" << z << '\n';
        exit(0);
    } else {
        cout << "OK " << l << " PYTAN\n";
        exit(0);
    }
}