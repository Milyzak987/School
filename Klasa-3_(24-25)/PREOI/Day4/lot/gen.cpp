#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 2e5;       // Maksymalna liczba miast
const ll MAXM = 4e5;       // Maksymalna liczba dróg powietrznych
const ll MAX_HEIGHT = 1e8; // Maksymalna minimalna wysokość przelotowa

void generateTest(int n, int m, int testId) {
    // Tworzenie ścieżki do pliku
    string folder = "in";
    system(("mkdir -p " + folder).c_str()); // Upewnienie się, że folder istnieje
    string fileName = folder + "/test" + to_string(testId) + ".in";
    ofstream outFile(fileName);

    // Liczba miast i dróg
    outFile << n << " " << m << "\n";

    // Generuj minimalne wysokości przelotowe
    vector<ll> heights(n + 1);
    heights[1] = 0; // Miasto 1: a1 = 0
    heights[n] = 0; // Miasto n: an = 0
    for (int i = 2; i < n; i++) {
        heights[i] = rand() % MAX_HEIGHT; // Losowe wysokości w przedziale [0, MAX_HEIGHT)
    }
    for (int i = 1; i <= n; i++) {
        outFile << heights[i] << " ";
    }
    outFile << "\n";

    // Generuj graf z losowymi połączeniami
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        do {
            u = rand() % n + 1;
            v = rand() % n + 1;
        } while (u == v || edges.count({u, v}) || edges.count({v, u}));
        edges.insert({u, v});
        outFile << u << " " << v << "\n";
    }

    outFile.close();
}

int main() {
    srand(time(0));

    int numTests = 10; // Liczba testów

    for (int testId = 1; testId <= numTests; testId++) {
        // Generuj losowe n i m dla każdego testu
        int n = rand() % 100 + 2; // Liczba miast (do 100 dla testów lokalnych, można zwiększyć do MAXN)
        int m = rand() % (2 * n) + n; // Liczba dróg, co najmniej n
        generateTest(n, m, testId);
    }

    return 0;
}
