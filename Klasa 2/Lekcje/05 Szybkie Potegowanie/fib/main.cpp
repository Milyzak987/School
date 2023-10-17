#include <iostream>
#include <map>
using namespace std;

const int MOD = 123456789;
map<int, int> F;

int f(int n) {
    if (F.count(n)) return F[n];
    int k = n / 2;
    if (n % 2 == 0) {
        return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % MOD;
    } else {
        return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % MOD;
    }
}

int main() {
    int n;
    F[0] = 1;
    F[1] = 1;
    cin >> n;
    cout << f(n - 1);
}