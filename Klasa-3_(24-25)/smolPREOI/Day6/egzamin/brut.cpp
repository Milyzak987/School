#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MAXN = 2e5 + 7;
int man[MAXN];
int ones[MAXN];

void update(int pos, int x) { man[pos] = x; }

int check(int l, int r, int x) {
    int count = 0;
    for (int i = l; i <= r; i++) {
        if (man[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    ones[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> man[i];
        if (man[i] == 1) {
            ones[i] = ones[i - 1] + 1;
        } else {
            ones[i] = ones[i - 1];
        }
    }

    while (q--) {
        char c;
        cin >> c;
        if (c == '?') {
            int a, b, c;
            cin >> a >> b >> c;
            cout << check(a, b, c) << "\n";
        } else {
            int a, b;
            cin >> a >> b;
            update(a, b);
        }
    }
}