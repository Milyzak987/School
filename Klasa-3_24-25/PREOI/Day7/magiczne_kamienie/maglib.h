#include <bits/stdc++.h>

int _n, _pytania = 0;
std::vector<char> _v;

void wyczaruj_odpowiedz(int n);

std::vector<int> zapytaj_maszyne(std::vector<int> _t) {
    ++_pytania;

    std::vector<int> _p;
    for (int _i = 0; _i < (int)_t.size(); ++_i) {
        _p.push_back(_t[_i]);
    }

    std::vector<int> _dlugosci;
    while (true) {
        std::vector<int> _q;
        for (int i = 0; i < int(_p.size()); ++i) {
            bool rem = false;
            if (i != 0 && _v[_p[i]] == 'R' && _v[_p[i - 1]] == 'T') rem = true;
            if (i != int(_p.size()) - 1 && _v[_p[i]] == 'R' && _v[_p[i + 1]] == 'T') rem = true;
            if (!rem) _q.push_back(_p[i]);
        }
        
        if (_p.size() == _q.size()) {
            if (_dlugosci.empty()) _dlugosci.push_back(_q.size());
            break;
        }
        _dlugosci.push_back(_q.size());
        std::swap(_p, _q);
    }
    
    return _dlugosci;
}

void odpowiedz(std::vector<char> _V) {
    std::cout << (_V == _v ? "OK" : "WA") << " " << _pytania << '\n';
}

int main() {
    std::cin >>  _n;
    _v.resize(_n);
    for (int _i = 0; _i < _n; ++_i)
    {
        std::cin >> _v[_i];
    }
    wyczaruj_odpowiedz(_n);
}
