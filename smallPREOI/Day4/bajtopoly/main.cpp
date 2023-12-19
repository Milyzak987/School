#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> tree(65538, -1);

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

bool cube(int a, int b) {
    if (a == b)
        return true;
    else if ((a == 1 && b == 6) || (a == 2 && b == 5) || (a == 3 && b == 4))
        return true;
    else
        return false;
}

int main() {
    int k, n;
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a] = b;
    }

    if (n == 0) {
        if (k == 1) {
            cout << 6;
        } else {
            long long result = power((power(2, k) - 2) % MOD, 4);
            result = (result * 6) % MOD;
            cout << result;
        }
        return 0;
    }

    long long nodes = pow(2, k) - 1;
    long long result = 1;
    for (int i = 1; i <= nodes; i++) {
        int x = tree[i];
        if (x == -1) {
            int child1, child2, parent;
            child1 = tree[i * 2];
            child2 = tree[i * 2 + 1];
            parent = tree[i / 2];
            if (parent == -1) {
                if (child1 == -1 || child2 == -1 || cube(child1, child2) || cube(child2, child1)) {
                    result = (result * 4) % MOD;
                } else {
                    result = (result * 2) % MOD;
                }
            } else {
                if (child1 == -1 && child2 == -1) {
                    result = (result * 4) % MOD;
                } else if ((child1 == -1 && (cube(child1, parent) || cube(parent, child1))) || (child2 == -1 && (cube(child2, parent) || cube(parent, child2)))) {
                    result = (result * 4) % MOD;
                } else if (parent != child1 && parent != child2 && child1 != child2) {
                    cout << 0;
                    return 0;
                } else if (parent == child1 && child1 == child2) {
                    result = (result * 4) % MOD;
                } else {
                    result = (result * 2) % MOD;
                }
            }
        }
    }
    cout << result;
    return 0;
}