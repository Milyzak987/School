#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 7;
vector<int> health[MAXN];
vector<int> last(MAXN, 1);
vector<int> length(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, hp;
    cin >> n >> hp;

    for (int i = 0; i < n; i++) {
        health[i].push_back(0);
        int k;
        cin >> k;
        length[i] = k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            health[i].push_back(health[i][j] + a);
        }
    }
    int count = 0, hp_new = hp;
    while (count < n) {
        for (int i = 0; i < n; i++) {
            if (last[i] > length[i]) {
                continue;
            }
            int j = last[i], x, max_hp = 0;
            while (hp + health[i][j] >= 0 && j <= length[i]) {
                x = health[i][j];
                if (x >= max_hp) {
                    max_hp = x;
                    last[i] = j;
                }
                j++;
            }
            last[i]++;
            hp_new += max_hp;
            if (last[i] > length[i]) {
                count++;
            }
        }
        hp = hp_new;
    }
    cout << hp_new;
    return 0;
}
