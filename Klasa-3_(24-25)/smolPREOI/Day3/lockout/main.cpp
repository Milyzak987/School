#include "loc_lib.h"
#include <deque>
using namespace std;
typedef long long ll;

const int MAXN = 2e6;
bool players[MAXN];
deque<int> p;

int main() {
    int n = daj_n();
    int m = 1 << n;

    int count = 0;
    for (int j = 0; j <= n / 2; j++) {
        for (int i = 1; i <= m; i++) {
            if (!players[i]) {
                count++;
                p.push_back(i);
            }
            if (count == 4) {
                count = 0;
                char odp = pytanie(p[0], p[2]);
                if (odp == '=') {
                    players[p[0]] = true;
                    players[p[2]] = true;
                    if (pytanie(p[1], p[3]) == '>') {
                        players[p[3]] = true;
                    } else {
                        players[p[1]] = true;
                    }
                } else if (odp == '>') {
                    players[p[1]] = true;
                    players[p[2]] = true;
                    if (pytanie(p[0], p[3]) == '>') {
                        players[p[3]] = true;
                    } else {
                        players[p[0]] = true;
                    }
                } else {
                    players[p[0]] = true;
                    players[p[3]] = true;
                    if (pytanie(p[1], p[2]) == '>') {
                        players[p[2]] = true;
                    } else {
                        players[p[1]] = true;
                    }
                }
                p.clear();
            }
        }
    }

    if (p.size() == 2) {
        if (pytanie(p[0], p[1]) == '>') {
            odpowiedz(p[0]);
        } else {
            odpowiedz(p[1]);
        }
    } else {
        odpowiedz(p[0]);
    }

    return 0;
}