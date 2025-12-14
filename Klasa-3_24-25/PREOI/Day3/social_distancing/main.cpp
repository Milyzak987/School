#include <iostream>
using namespace std;

const int MAXN = 1e5 + 7;
const int MAXM = 5e5 + 7;
bool units[MAXM];
int groups[MAXM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    if (n <= 200) {
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            units[x] = true;
            int count = 0;
            for (int j = 0; j < MAXM; j++) {
                while (units[j]) {
                    count++;
                    j++;
                }
                if (count != 0) {
                    res += (count + 1) / 2;
                    count = 0;
                }
            }
            cout << res << " ";
            res = 0;
        }
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (units[x]) {
            cout << res << " ";
            continue;
        }
        units[x] = true;
        if (!units[x + 1] && !units[x - 1]) {
            res++;
        } else if (((x + 1) % 4 == 0) && units[x - 2]) {
            res++;
        } else if (((x - 1) % 4 == 0) && units[x + 2]) {
            res++;
        }

        cout << res << " ";
    }
}