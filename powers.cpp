#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exponent) {
    long long result = 1;
    base %= MOD;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

int main() {
    long long k;
    cin >> k;

    long long result = power((power(2, k) - 2 + MOD) % MOD, 4);
    result = (result * 6) % MOD;

    cout << result << endl;

    return 0;
}
