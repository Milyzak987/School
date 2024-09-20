#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 200007;
int num[MAXN];
int desc[MAXN];
int asc[MAXN];
int mer[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    asc[0] = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] > num[i - 1]) {
            asc[i] = asc[i - 1] + 1;
        } else {
            asc[i] = 1;
        }
    }
    desc[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (num[i] > num[i + 1]) {
            desc[i] = desc[i + 1] + 1;
        } else {
            desc[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        mer[i] = desc[i] + asc[i];
    }
    int res;
    res = *max_element(mer, mer + n);
    cout << res - 1;
}