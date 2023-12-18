#include <algorithm>
#include <vector>

#include "sejlib.h"
using namespace std;

int main() {
    int i;
    vector<int> pos1, pos2;
    vector<pair<int, int>> pos;
    int n = init();

    int num = wywiad(1, n);
    int chk = wywiad(n, 1);
    pos.push_back({chk, n});

    for (int i = 2; i < n; ++i) {
        pos.push_back({wywiad(i, 1), i});
    }
    sort(pos.begin(), pos.end());

    int max_count = 1, good = pos[0].first, curr_count = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (pos[i].first == pos[i - 1].first)
            curr_count++;
        else
            curr_count = 1;
        if (curr_count > max_count) {
            max_count = curr_count;
            good = pos[i - 1].first;
        }
    }

    for (auto u : pos) {
        if (u.first == good) {
            pos1.push_back(u.second);
        } else {
            pos2.push_back(u.second);
        }
    }

    if (pos1.size() == pos2.size()) {
        if (wywiad(1, n) == num) {
            if (chk == good) {
                sort(pos2.begin(), pos2.end());
                odpowiedz(pos2);
            } else {
                sort(pos1.begin(), pos1.end());
                odpowiedz(pos1);
            }
        } else {
            if (chk != good) {
                sort(pos2.begin(), pos2.end());
                odpowiedz(pos2);
            } else {
                sort(pos1.begin(), pos1.end());
                odpowiedz(pos1);
            } 
        }
    } else {
        if (chk == good) {
            if(num == wywiad(pos1[0], n)){
                sort(pos2.begin(), pos2.end());
                odpowiedz(pos2);
            } else{
                pos2.push_back(1);
                sort(pos2.begin(), pos2.end());
                odpowiedz(pos2);
            }
        } else {
            if(num + 1 == wywiad(pos1[0], n)){
                sort(pos2.begin(), pos2.end());
                odpowiedz(pos2);
            } else{
                pos2.push_back(1);
                sort(pos2.begin(), pos2.end());
                odpowiedz(pos2);
            }
        }
    }
}
