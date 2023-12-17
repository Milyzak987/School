#include <iostream>
#include <map>
#include <vector>
using namespace std;

int liczby[1000 * 1000 + 5];
map<int, long long> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    long long wynik = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> liczby[i];
        liczby[i] ^= liczby[i - 1];
    }
    m[0]++;
    for (int i = 1; i <= n; i++) {
        long long szuk = liczby[i] ^ k;
        wynik += m[szuk];
        m[liczby[i]]++;
    }
    cout << wynik;
    // a long long'ow nie potrzebujesz?
    return 0;
}