#include <bits/stdc++.h>

#include "chalib.h"
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1e5 + 7;

vector<bool> paths(MAXN);
vector<bool> used(MAXN, false);

int main() {
    int n = daj_n();

    if (n < 2) {
        odpowiedz({});
        return 0;
    }

    int count_friends = 0;
    int count_enemies = 0;

    for (int i = 1; i < n; i++) {
        if (zapytaj(i, i + 1)) {
            paths[i] = true;
            count_friends++;
        } else {
            paths[i] = false;
            count_enemies++;
        }
    }

    int target = (count_friends >= count_enemies) ? 1 : 0;

    vector<pair<int, int>> result;

    for (int i = 1; i < n; i++) {
        if (paths[i] == target) {
            if (!used[i] && !used[i + 1]) {
                result.push_back({i, i + 1});

                used[i] = true;
                used[i + 1] = true;
            }
        }
    }

    odpowiedz(result);
}
