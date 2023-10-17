#include <iostream>
#include <vector>

using namespace std;

const int MOD = 123456789;

vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    vector<vector<long long>> C(n, vector<long long>(p, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    return C;
}

vector<vector<long long>> matrix_power(vector<vector<long long>>& A, int n) {
    int m = A.size();
    if (n == 1) return A;

    vector<vector<long long>> half_pow = matrix_power(A, n / 2);
    vector<vector<long long>> result = multiply(half_pow, half_pow);

    if (n % 2 == 0) {
        return result;
    } else {
        return multiply(result, A);
    }
}

long long fibonacci(int n) {
    if (n == 1) return 1;

    vector<vector<long long>> T = {{1, 1}, {1, 0}};
    T = matrix_power(T, n - 1);

    return T[0][0] % MOD;
}

int main() {
    int n;
    cin >> n;

    long long result = fibonacci(n);
    cout << result;

    return 0;
}