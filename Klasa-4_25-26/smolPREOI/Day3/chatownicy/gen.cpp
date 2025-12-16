#include <bits/stdc++.h>
using namespace std;

const int M = 1;

bool ans[11][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, M);

    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            ans[i][j] = dist(gen);
        }
    }
    for (int i = 1; i < 11; i++) {
        for (int j = i + 1; j < 11; j++) {
            if (ans[i][j]) cout << i << " " << j << '\n';
        }
    }

    cout << "\n\n";

    for (int i = 1; i < 11; i++) {
        for (int j = i + 1; j < 11; j++) {
            if (!ans[i][j]) cout << i << " " << j << '\n';
        }
    }
}