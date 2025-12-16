#include "chalib.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = daj_n();

    if (n < 2) {
        odpowiedz({});
        return 0;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    mt19937 rng(1337);
    shuffle(p.begin(), p.end(), rng);

    vector<pair<int, int>> friends;
    vector<pair<int, int>> enemies;

    int queries_used = 0;
    int max_queries = n;

    for (int i = 0; i + 1 < n; i += 2) {
        if (zapytaj(p[i], p[i + 1])) {
            friends.push_back({p[i], p[i + 1]});
        } else {
            enemies.push_back({p[i], p[i + 1]});
        }
        queries_used++;
    }

    while (queries_used + 1 < max_queries && !friends.empty() && !enemies.empty()) {
        pair<int, int> p_friend = friends.back();
        friends.pop_back();

        pair<int, int> p_enemy = enemies.back();
        enemies.pop_back();

        int u = p_friend.first;
        int v = p_friend.second;

        int x = p_enemy.first;
        int y = p_enemy.second;

        bool res1 = zapytaj(u, x);
        queries_used++;

        if (queries_used == max_queries) {
            if (res1) {
                friends.push_back({u, x});

            } else {
                enemies.push_back({u, x});
            }
            break;
        }

        bool res2 = zapytaj(v, y);
        queries_used++;

        if (res1)
            friends.push_back({u, x});
        else
            enemies.push_back({u, x});

        if (res2)
            friends.push_back({v, y});
        else
            enemies.push_back({v, y});
    }

    if (friends.size() >= enemies.size()) {
        odpowiedz(friends);
    } else {
        odpowiedz(enemies);
    }

    return 0;
}
