#include <bits/stdc++.h>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

void generate_test(int n, string filename) {
    ofstream out(filename); // Otwórz plik do zapisu

    // Zapisz liczbę składników
    out << n << '\n';

    // Losowanie ilości składników x[i]
    for (int i = 0; i < n; i++) {
        out << (rand() % 1000000000 + 1) << ' ';
    }
    out << '\n';

    // Losowanie składników w przepisie Bajtka a[i]
    for (int i = 0; i < n; i++) {
        out << (rand() % 100 + 1) << ' ';
    }
    out << '\n';

    // Losowanie składników w przepisie Bitka b[i]
    for (int i = 0; i < n; i++) {
        out << (rand() % 100 + 1) << ' ';
    }
    out << '\n';

    out.close(); // Zamknij plik
}

int main() {
    srand(time(0)); // Inicjalizacja generatora losowego

    int T = 10; // Liczba testów

    fs::create_directory("in");

    for (int t = 1; t <= T; t++) {
        int n = rand() % 10 + 1; // Losowanie liczby składników w zakresie [1, 100000]
        string filename = "in/test" + to_string(t) + ".in"; // Nazwa pliku
        generate_test(n, filename); // Generowanie testu i zapis do pliku
    }

    cout << "Wygenerowano " << T << " testów w folderze 'in'." << endl;
    return 0;
}
