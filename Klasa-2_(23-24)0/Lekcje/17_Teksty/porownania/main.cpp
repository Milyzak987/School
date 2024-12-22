#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const long long P = 31;
const int MAXN = 2e5 + 7;
long long pwr[MAXN];
long long pref[MAXN];
string s;

long long hash_pref(int l, int r) {
    return (pref[r] - ((pref[l - 1] * pwr[r - l + 1]) % MOD) + MOD) % MOD;
}

int sprawdz(int a, int b, int l) {
    if (hash_pref(a, a + l - 1) == hash_pref(b, b + l - 1)) return 0;
    return (s[a + l - 1] > s[b + l - 1] ? 1 : -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pwr[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        pwr[i] = (pwr[i - 1] * P) % MOD;
    }

    cin >> s;
    s = "$" + s;

    for (int i = 1; i <= (int)s.length(); i++) {
        pref[i] = (pref[i - 1] * P + s[i]) % MOD;
    }

    int m;
    cin >> m;

    while (m--) {
        int a, b, l;
        cin >> a >> b >> l;

        int start = 1, endd = l;
        while (start < endd) {
            int mid = (start + endd) / 2;
            if (sprawdz(a, b, mid) == 0) {
                start = mid + 1;
            } else {
                endd = mid;
            }
        }

        int x = sprawdz(a, b, start);
        if (x == 0) {
            cout << "=\n";
        } else if (x > 0) {
            cout << ">\n";
        } else {
            cout << "<\n";
        }
    }

    return 0;
}
