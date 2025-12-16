#include <bits/stdc++.h>

#include "chalib.h"
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 7;

vector<bool> paths(MAXN);

int main() {
    int n = daj_n();

    if (n < 2) {
        odpowiedz({});
        return 0;
    }

    vector<pii> friends;
    vector<pii> enemies;

    for (int i = 1; i < n; i++) {
        paths[i] = zapytaj(i, i + 1);
    }

    for (int i = 1; i < n; i++) {
        if (paths[i]) {
            friends.push_back({i, i + 1});
        } else {
            enemies.push_back({i, i + 1});
        }
        if (i != n - 1 && paths[i + 1] == paths[i]) {
            i++;
        }
    }

    if (friends.size() >= enemies.size()) {
        odpowiedz(friends);
    } else {
        odpowiedz(enemies);
    }

    return 0;
}
