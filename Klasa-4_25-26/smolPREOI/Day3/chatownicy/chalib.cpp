#include "chalib.h"
#include <bits/stdc++.h>
using namespace std;

int _n;
bool _initialized = false;
bool _optymalne_k = false;
int _status[107][107];

static void _initialize() {
    if (_initialized)
        return;
    _initialized = true;
    std::cin >> _n;
}

int daj_n() {
    _initialize();
    return _n;
}

void optymalne(int k) {
    _optymalne_k = true;
}

bool zapytaj(int i, int j) {
    if(i == j) {
        cout << "W pytaniu i = j!" << "\n";
        exit(0);
    }
    if(!_optymalne_k) {
        cout << "Nie wywołano funkcji optymalne!" << "\n";
        exit(0);
    }
    cout << "Odpowiedz na pytanie " << i << " " << j << ": " << "\n";
    bool odp;
    cin >> odp;
    if(odp) {
        _status[i][j] = _status[j][i] = 1;
    }
    else {
        _status[i][j] = _status[j][i] = 2;
    }
    return odp;
}

void odpowiedz(std::vector<std::pair<int, int>> a) {
    if(!_optymalne_k) {
        cout << "Nie wywołano funkcji optymalne!" << "\n";
        exit(0);
    }
    int status1 = _status[a[0].first][a[0].second];
    for(auto x : a) {
        if(_status[x.first][x.second] == 0) {
            cout << "Podano parę bez określonego statusu!" << "\n";
            exit(0);
        }
        if(_status[x.first][x.second] != status1) {
            cout << "Podane pary nie są tego samego typu!" << "\n";
            exit(0);
        }
    }
    cout << "OK" << "\n";
    exit(0);
}
