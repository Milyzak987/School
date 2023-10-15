#include <iomanip>
#include <iostream>
using namespace std;

double wie[6];

double horner(double wie[], double x) {
    double wynik = wie[0];

    for (int i = 1; i <= 5; i++)
        wynik = wynik * x + wie[i];

    return wynik;
}

double polowienie_przedzialow() {
    double l = -5, r = 5, eps = 0.000001;

    if (horner(wie, l) == 0.0) return l;
    if (horner(wie, r) == 0.0) return r;

    double mid;

    while (r - l > eps) {
        mid = (l + r) / 2;

        if (horner(wie, mid) == 0.0)
            return mid;

        if (horner(wie, l) * horner(wie, mid) < 0)
            r = mid;
        else
            l = mid;
    }
    return (l + r) / 2;
}

int main() {
    for (int i = 0; i < 6; i++) {
        cin >> wie[i];
    }

    cout << fixed << setprecision(6) << polowienie_przedzialow();

    return 0;
}
