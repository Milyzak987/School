#include <algorithm>
#include <iostream>

using namespace std;

void skroc(long long liczba1, long long liczba2) {
    long long nwd = __gcd(liczba1, liczba2);
    const long long pop_liczba1 = liczba1, pop_liczba2 = liczba2;
    liczba1 /= nwd;
    liczba2 /= nwd;
    nwd = __gcd(pop_liczba1, liczba2);
    liczba2 /= nwd;
    cout << liczba1 << ' ' << liczba2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long il_zapytan, liczba1, liczba2;
    cin >> il_zapytan;
    for (long long i = 0; i < il_zapytan; i++) {
        cin >> liczba1 >> liczba2;
        skroc(liczba1, liczba2);
    }
}