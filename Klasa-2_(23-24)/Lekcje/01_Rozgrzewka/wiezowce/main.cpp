#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "wie.h"
using namespace std;

long long fun(int a, long long b) {
    long long r = 1e18 + 2, mid;
    while (b < r) {
        mid = (b + r) / 2;
        bool check = zamowienie(a, mid);
        if (check) b = mid + 1;
        else r = mid;
    }
    return b - 1;
}

int main() {
    int i, n = wezN();
    long long naj = 0, x;
    vector<int> kol(n);
    for (i = 0; i < n; i++) kol[i] = i + 1;
    random_shuffle(kol.begin(), kol.end());
    for (int i : kol) {
        if (!zamowienie(i, naj + 1)) continue;
        if (fun(i, naj + 1) >= naj) {
            naj = max(naj, fun(i, naj + 1));
            x = i;
        }
    }
    if (zamowienie(x, 1000000000000000000)) {
        odpowiedz(1000000000000000000);
        return 0;
    }
    odpowiedz(naj);
    return 0;
}