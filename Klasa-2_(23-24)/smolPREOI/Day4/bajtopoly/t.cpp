#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long power(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    long long k, n;
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
    }

    if (n == 0) {
        if (k == 1) {
            cout << 6;
        } else {
            long long v = 1LL << k;
            long long result = power(4, v - 2);
            result = (result * 6) % MOD;
            cout << result;
        }
        return 0;
    } else {
        cout << -1;
    }
}