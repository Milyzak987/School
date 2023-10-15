#include <iostream>

using namespace std;
long long minSum(int tab[], int il_kocertow, int il_planowanych_koncertow) {
    long long wynik = 0;
    for (int i = 0; i < il_planowanych_koncertow; i++) wynik += tab[i];
    long long akt_wynik = wynik;
    for (int i = il_planowanych_koncertow; i < il_kocertow; i++) {
        akt_wynik += tab[i] - tab[i - il_planowanych_koncertow];
        wynik = min(wynik, akt_wynik);
    }

    return wynik;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_koncertow, il_planowanych_koncertow;
    cin >> il_koncertow >> il_planowanych_koncertow;
    int koncerty[il_koncertow];
    for (auto &koncert : koncerty) {
        cin >> koncert;
    }
    cout << minSum(koncerty, il_koncertow, il_planowanych_koncertow) << "\n";
}