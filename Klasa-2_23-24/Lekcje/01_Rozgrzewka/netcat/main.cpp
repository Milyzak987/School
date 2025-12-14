#include <iostream>
#include <map>
using namespace std;

const int MAXN = 2e5 + 7;
map<string, int> mp;
int kra[MAXN];

int Find(int x) {
    if (kra[x] == x) return x;
    kra[x] = Find(kra[x]);
    return kra[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    kra[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= MAXN; i++) {
        kra[i] = i;
    }

    int ind = 0;

    int q;
    cin >> q;
    while (q--) {
        string s, a, b;
        cin >> s >> a >> b;

        int A = mp[a], B = mp[b];
        if (a != b && A == 0) {
            ind++;
            mp[a] = ind;
            A = ind;
        }
        if (a != b && B == 0) {
            ind++;
            mp[b] = ind;
            B = ind;
        }

        if (s[0] == 'c') {
            if (a != b) Union(A, B);
        } else {
            if (a == b) {
                cout << "Tak\n";
            } else {
                cout << (Find(A) == Find(B) ? "Tak" : "Nie") << "\n";
            }
        }
    }

    return 0;
}