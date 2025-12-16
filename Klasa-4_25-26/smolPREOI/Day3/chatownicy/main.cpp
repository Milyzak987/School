#include "chalib.h"
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n = daj_n();

    if (n < 2) {
        odpowiedz({});
        return 0;
    }

    vector<pii> friends;
    vector<pii> enemies;

    int q_used = 0;
    int maxQ = n;

    for (int i = 1; i < n; i += 2) {
        if (zapytaj(i, i + 1)) {
            friends.push_back({i, i + 1});
        } else {
            enemies.push_back({i, i + 1});
        }
        q_used++;
    }

    while (q_used + 1 < maxQ && !friends.empty() && !enemies.empty()) {
        pii p_friend = friends.back();
        friends.pop_back();

        pii p_enemy = enemies.back();
        enemies.pop_back();

        int u = p_friend.first;
        int v = p_friend.second;

        int x = p_enemy.first;
        int y = p_enemy.second;

        bool res1 = zapytaj(u, x);
        q_used++;

        if (q_used == maxQ) {
            if (res1) {
                friends.push_back({u, x});

            } else {
                enemies.push_back({u, x});
            }
            break;
        }

        bool res2 = zapytaj(v, y);
        q_used++;

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
