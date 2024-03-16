#include <iostream>
using namespace std;

const int MOD = 1000000007;
 
int power(long long x, long long y, long long MOD) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cout << power(a, power(b, c, MOD-1), MOD) << "\n";
    }
}