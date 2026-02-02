#include <bits/stdc++.h>
#include "rowlib.h"

using namespace std;

int _T;
int _N;
vector<long long> _V;
int _K;

void ZapytajChrisa(long long s, long long t, long long& mn, long long& mx) {
    int i = 0;
    while(i < _N && _V[i] < s) i++;
    if(i == _N) {
        mn = mx = -1;
        return;
    }
    mn = _V[i];
    while(i < _N && _V[i] <= t) i++, _K += _T == 2;
    mx = _V[i - 1];
    _K++;
    cout << _K << '\n';
}

int main() {
    cin >> _T >> _N;
    _V.resize(_N);
    for(int i = 0; i < _N; i++) cin >> _V[i];
    long long skarpa = 0;
    for(int i = 1; i < _N; i++) skarpa = max(skarpa, _V[i] - _V[i - 1]);
    if(ZnajdzSkarpe(_T, _N) == skarpa) cout << "OK, K = " << _K << '\n';
    else cout << _T << " Zla odpowiedz\n";
}
