#include <bits/stdc++.h>
#include "ulilib.h"

using namespace std;
int a, b, n1, xval, yval, q;
int cnt = 0;
int lic = 0;

void init(int &n, int &x, int &y) {
    if (cnt > 0) {
        cout << "LICZBY JUŻ BYŁY PODANE WCZEŚNIEJ" << '\n';
        exit(0);
    }
    cnt++;
    cin >> n >> q >> a >> b >> x >> y;
    n1 = n;
    xval = x;
    yval = y;
}

int pytaj(vector<int> vec) {
    lic++;
    if (lic > q) {
        cout << "ZA DUŻO PYTAŃ" << '\n';
        exit(0);
    }
    int ans = 0;
    set<int> S;
    for (auto p: vec) {
        if (p < 1 || p > n1) {
            cout << "LICZBA SPOZA PRZEDZIAŁU" << '\n';
            exit(0);
        }
        if (S.find(p) != S.end()) {
            cout << "LICZBA SIĘ POWTARZA W ZAPYTANIU" << '\n';
            exit(0);
        }
        S.insert(p);
        if (p == a || p == b) {
            ans ^= yval;
        }
        else {
            ans ^= xval;
        }
    }
    return ans;
}

void odpowiedz(int p1, int p2) {
    if (p1 < 1 || p1 > n1) {
        cout << "POZYCJA PIERWSZA SPOZA PRZEDZIAŁU" << '\n';
        exit(0);
    }
    if (p2 < 1 || p2 > n1) {
        cout << "POZYCJA DRUGA SPOZA PRZEDZIAŁU" << '\n';
        exit(0);
    }
    if (p1 >= p2) {
        cout << "POZYCJA PIERWSZA WIĘKSZA NIŻ POZYCJA DRUGA" << '\n';
        exit(0);
    }
    if (a > b) {
        swap(a, b);
    }
    if ((p1 != a) || (p2 != b)) {
        cout << "ZŁA ODPOWIEDŹ" << '\n';
        exit(0);
    }
    cout << "OK" << '\n';
    exit(0);
}