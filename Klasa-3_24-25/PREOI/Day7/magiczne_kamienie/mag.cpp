#include "maglib.h"
#include <bits/stdc++.h>

using namespace std;

void wyczaruj_odpowiedz(int n) {
    vector<char> res(1000);
    deque<int> dknow;
    res[0] = 'T';
    for (int i = 1; i < 1000; i++) {
        dknow.push_front(i);
    }
    while (dknow.size() > 1) {
        vector<int> v = zapytaj_maszyne({dknow[0], 0, dknow[1]});
        if (v[0] == 1) {
            res[dknow[0]] = 'R';
            res[dknow[1]] = 'R';
            dknow.pop_front();
            dknow.pop_front();
        } else if (v[0] == 3) {
            res[dknow[0]] = 'T';
            res[dknow[1]] = 'T';
            dknow.pop_front();
            dknow.pop_front();
        } else {
            vector<int> v1 = zapytaj_maszyne({0, dknow[0]});
            if (v1[0] == 1) {
                res[dknow[0]] = 'R';
                res[dknow[1]] = 'T';
                dknow.pop_front();
                dknow.pop_front();
            } else {
                res[dknow[0]] = 'T';
                res[dknow[1]] = 'R';
                dknow.pop_front();
                dknow.pop_front();
            }
        }
    }
    if (!dknow.empty()) {
        vector<int> v = zapytaj_maszyne({0, dknow[0]});
        if (v[0] == 1) {
            res[dknow[0]] == 'R';
            dknow.pop_front();
        } else {
            res[dknow[0]] = 'T';
            dknow.pop_front();
        }
    }
    odpowiedz(res);
}
