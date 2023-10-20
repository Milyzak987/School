#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int il_liczb, il_zapytan, i, liczba, od_ilu, do_ilu;
    cin >> il_liczb >> il_zapytan;
    int liczby[il_liczb + 1];
    liczby[0] = 0;
    for (i = 1; i <= il_liczb; i++) {
        cin >> liczba;
        liczby[i] = liczba + liczby[i - 1];
    }
    for (i = 0; i < il_zapytan; i++) {
        cin >> od_ilu >> do_ilu;
        cout << liczby[do_ilu] - liczby[od_ilu - 1] << "\n";
    }
}