#include <bits/stdc++.h>

#include "chalib.h"

using namespace std;

struct Conflict {
    pair<int, int> pair_c0;
    pair<int, int> pair_c1;
};

int main() {
    int n = daj_n();

    if (n == 1) {
        odpowiedz({});
        return 0;
    }

    deque<int> path;

    vector<Conflict> conflicts;

    int path_color = -1;

    for (int v = 1; v <= n; ++v) {
        if (path.empty()) {
            path.push_back(v);
            continue;
        }

        int u = path.back();

        bool result = zapytaj(u, v);
        int current_edge_color = result ? 1 : 0;

        if (path.size() == 1) {
            path.push_back(v);
            path_color = current_edge_color;
        } else {
            if (current_edge_color == path_color) {
                path.push_back(v);
            } else {
                int prev_u = path[path.size() - 2];

                Conflict conf;

                pair<int, int> p_path = {prev_u, u};

                pair<int, int> p_new = {u, v};

                if (path_color == 0) {
                    conf.pair_c0 = p_path;
                    conf.pair_c1 = p_new;
                } else {
                    conf.pair_c1 = p_path;
                    conf.pair_c0 = p_new;
                }

                conflicts.push_back(conf);

                path.pop_back();
                path.pop_back();

                if (path.size() < 2) {
                    path_color = -1;
                }
            }
        }
    }

    int score0 = conflicts.size();
    if (path_color == 0 && path.size() >= 2) {
        score0 += path.size() / 2;
    }

    int score1 = conflicts.size();
    if (path_color == 1 && path.size() >= 2) {
        score1 += path.size() / 2;
    }

    vector<pair<int, int>> result_pairs;

    if (score1 > score0) {
        for (const auto& c : conflicts) {
            result_pairs.push_back(c.pair_c1);
        }
        if (path_color == 1 && path.size() >= 2) {
            for (size_t i = 0; i + 1 < path.size(); i += 2) {
                result_pairs.push_back({path[i], path[i + 1]});
            }
        }
    } else {
        for (const auto& c : conflicts) {
            result_pairs.push_back(c.pair_c0);
        }
        if (path_color == 0 && path.size() >= 2) {
            for (size_t i = 0; i + 1 < path.size(); i += 2) {
                result_pairs.push_back({path[i], path[i + 1]});
            }
        }
    }

    odpowiedz(result_pairs);
    return 0;
}