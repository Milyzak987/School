#include "szylib.h"

#include <bits/stdc++.h>

using namespace std;

void Zaszyfruj(int X, int Y, int N, string A) {
    bool res[8][8];
    for (int i = 0; i < 8; i++) {
        res[i][0] = 1;
        res[0][i] = 1;
        res[i][7] = 1;
        res[7][i] = 1;
    }
    // res[0][0] = 1;
    // res[7][7] = 1;
    // res[0][7] = 1;
    // res[7][0] = 1;

    res[(X + 1) % 8][0] = 0;
    res[(X + 1) % 8][7] = 0;
    res[0][(Y + 1) % 8] = 0;
    res[7][(Y + 1) % 8] = 0;

    int idx = 0;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if ((i != X && j != Y)) {
                if (idx < N) {
                    res[i][j] = (A[idx] == 'A');
                    idx++;
                } else {
                    res[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i != X && j != Y)) {
                Oznacz(i, j, res[i][j]);
            }
        }
    }
}

string Odszyfruj(int N, vector<vector<int>> A) {
    string res;
    int goodX = 0, goodY = 0;
    int X, Y;

    bool b = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            X = i;
            Y = j;
            b = (A[(X + 1) % 8][0] == 0);
            b = (b && (A[(X + 1) % 8][7] == 0));
            b = (b && (A[0][(Y + 1) % 8] == 0));
            b = (b && (A[7][(Y + 1) % 8] == 0));
            for (int k = 0; k < 8; k++) {
                if (k != X && 0 != Y && k != (X + 1) % 8 && 0 != (Y + 1) % 8) {
                    b = (b && (A[k][0] == 1));
                }
                if (0 != X && k != Y && k != (Y + 1) % 8 && 0 != (X + 1) % 8) {
                    b = (b && (A[0][k] == 1));
                }
                if (k != X && 7 != Y && k != (X + 1) % 8 && 0 != (Y + 1) % 8) {
                    b = (b && (A[k][7] == 1));
                }
                if (7 != X && k != Y && k != (Y + 1) % 8 && 0 != (X + 1) % 8) {
                    b = (b && (A[7][k] == 1));
                }
            }
            if (b) {
                goodX = X;
                goodY = Y;
            }
        }
    }

    int idx = 0;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 7; j++) {
            if ((i != goodX && j != goodY)) {
                if (idx < N) {
                    idx++;
                    if (A[i][j] == 1) {
                        res += 'A';
                    } else {
                        res += 'B';
                    }
                }
            }
        }
    }
    return res;
}