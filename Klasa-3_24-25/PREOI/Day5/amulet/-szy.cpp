#include "szylib.h"

#include <bits/stdc++.h>

using namespace std;

void Mark(int a, int b, int c, int X, int Y) {
    if (a != X && b != Y) {
        Oznacz(a, b, c);
    }
}

void Zaszyfruj(int X, int Y, int N, string A) {
    int akt = 0;
    for (int i = 0; i < 8; i++) {
        Mark(i, i, 1, X, Y);
        Mark(i, 7 - i, 1, X, Y);
    }
    if (X == 7 && Y == 7) {
        Mark(0, 0, 0, X, Y);
    } else if (X == 7) {
        Mark(0, 0, 0, X, Y);
        Mark(0, 8, 0, X, Y);
        Mark(Y + 1, Y + 1, 0, X, Y);
        Mark(7 - (Y + 1), Y + 1, 0, X, Y);
    } else if (Y == 7) {
        Mark(0, 0, 0, X, Y);
        Mark(8, 0, 0, X, Y);
        Mark(X + 1, X + 1, 0, X, Y);
        Mark(X + 1, 7 - (X + 1), 0, X, Y);
    } else {
        Mark(Y + 1, Y + 1, 0, X, Y);
        Mark(7 - (Y + 1), Y + 1, 0, X, Y);
        Mark(X + 1, X + 1, 0, X, Y);
        Mark(X + 1, 7 - (X + 1), 0, X, Y);
    }

    int idx = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i != X && j != Y) && (i != j) && (i != 7 - j)) {
                if (idx < N) {
                    Oznacz(i, j, A[idx] == 'A');
                    idx++;
                } else {
                    Oznacz(i, j, 0);
                }
            }
        }
    }
}

string Odszyfruj(int N, vector<vector<int>> A) {
    string res;
    int X, Y;

    int first = -1, second = -1;
    for (int i = 0; i < 8; i++) {
        if(A[i][i] == 0);
    }
    return res;
}