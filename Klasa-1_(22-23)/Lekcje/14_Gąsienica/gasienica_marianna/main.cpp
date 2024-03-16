#include <iostream>

using namespace std;

int rzad[1000002] = {0};

int gasienica(int dl_rzedu, int wymagana_ilosc_roz) {
    int wyn = 1000002, glowa = 0, ogon = 1, akt_sum = 0, il_kapust = 0;
    while (glowa < dl_rzedu) {
        glowa++;
        akt_sum += rzad[glowa];
        if (rzad[glowa] == 0) {
            il_kapust++;
        }
        if (akt_sum < wymagana_ilosc_roz) {
            continue;
        }
        if (akt_sum == wymagana_ilosc_roz) {
            wyn = min(wyn, il_kapust);
        }
        while (ogon < glowa && akt_sum >= wymagana_ilosc_roz) {
            akt_sum -= rzad[ogon];
            if (rzad[ogon] == 0) {
                il_kapust--;
            }
            ogon++;
            if (akt_sum == wymagana_ilosc_roz) {
                wyn = min(wyn, il_kapust);
            }
        }
    }
    return wyn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dl_rzedu, wymagana_ilosc_roz, wynik;
    cin >> dl_rzedu >> wymagana_ilosc_roz;
    for (int i = 1; i <= dl_rzedu; i++) {
        cin >> rzad[i];
    }
    wynik = gasienica(dl_rzedu + 1, wymagana_ilosc_roz);
    if (wynik == 1000002) {
        cout << "NIE";
    } else {
        cout << wynik;
    }
    cout << "\n";
}