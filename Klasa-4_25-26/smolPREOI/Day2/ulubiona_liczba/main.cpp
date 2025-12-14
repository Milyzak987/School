#include "ulilib.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    init(n, x, y);

    int dif = x ^ y;
    int ixr = 0;

    for (int b = 0; b < 10; ++b) {
        vector<int> P;
        for (int i = 1; i <= n; ++i) {
            if ((i >> b) & 1) {
                P.push_back(i);
            }
        }

        if (!P.empty()) {
            int res = pytaj(P);
            
            int expected = (P.size() % 2 != 0) ? x : 0;
            
            if ((res ^ expected) == dif) {
                ixr |= (1 << b);
            }
        }
    }

    int sep = -1;
    for (int b = 0; b < 10; ++b) {
        if ((ixr >> b) & 1) {
            sep = b;
            break;
        }
    }

    vector<int> candidates;
    for (int i = 1; i <= n; ++i) {
        if ((i >> sep) & 1) {
            candidates.push_back(i);
        }
    }

    int l = 0;
    int r = candidates.size() - 1;
    
    while (l < r) {
        int mid = (l + r) / 2;
        
        vector<int> P;
        for (int i = l; i <= mid; ++i) {
            P.push_back(candidates[i]);
        }
        
        int res = pytaj(P);
        int expected = (P.size() % 2 != 0) ? x : 0;
        
        if ((res ^ expected) == dif) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    int p1 = candidates[l];
    int p2 = p1 ^ ixr;

    if (p1 > p2) swap(p1, p2);
    odpowiedz(p1, p2);

    return 0;
}