#include <iostream>
#include <vector>
namespace {
const int Limit = 2e5;
int n, ileZapytan = 0;
bool czyInit = 0;
std::vector<int> czapki;
void Error() {
    std::cout << std::endl << "[kralib]: Niepoprawne zapytanie" << std::endl;
    exit(0);
}
int _init() {
    if (czyInit) {
        std::cout << std::endl << "[kralib]: Funkcje init wywolano drugi raz" << std::endl;
        exit(0);
    }
    czyInit = 1;
    std::cin >> n;
    czapki.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> czapki[i];
    }
    return n;
}
int _RoznicaCzapek(int l, int p) {
    if (!czyInit) {
        std::cout << std::endl << "[kralib]: Nie wywolano funkcji init" << std::endl;
        exit(0);
    }
    ileZapytan++;
    if (ileZapytan > Limit) {
        std::cout << std::endl << "[kralib]: Ilosc zapytan przekracza " << Limit << std::endl;
        exit(0);
    }

    if (l > p || l < 0 || n <= p) {
        std::cout << std::endl << l << " " << p << std::endl;
        Error();
    }
    int minn = n, maxx = -1;
    for (int i = l; i <= p; i++) {
        minn = std::min(minn, czapki[i]);
        maxx = std::max(maxx, czapki[i]);
    }
    return maxx - minn;
}
void _Odpowiedz(std::vector<int> W) {
    if (!czyInit) {
        std::cout << std::endl << "[kralib]: Nie wywolano funkcji init" << std::endl;
        exit(0);
    }
    if (W.size() != n) {
        Error();
    }
    for (int i = 0; i < n; i++) {
        if (W[i] != czapki[i]) {
            std::cout << std::endl << "Zla odpowiedz roznica dla i=" << i << std::endl;
            exit(0);
        }
    }
    std::cout << std::endl << "Poprawna odpowiedz" << std::endl;
    std::cout << "Ilosc zapytan = " << ileZapytan << std::endl;
    std::cout << "Program konczy dzialanie" << std::endl;
    exit(0);
}
} // namespace
int init() { return _init(); }
int RoznicaCzapek(int l, int p) { return _RoznicaCzapek(l, p); }
void Odpowiedz(std::vector<int> W) { _Odpowiedz(W); }
