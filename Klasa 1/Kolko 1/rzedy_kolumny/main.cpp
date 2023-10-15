#include <iostream>
#include <vector>
#include <chrono>
#include <numeric> // Accumulate

using namespace std;

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    // Define variables
    int n=1000, m=1000;
    // cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<long long> row_sums(n), col_sums(m);

    // Read input and compute row and column sums
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cin >> matrix[i][j];
            matrix[i][j]=i+j;
        }
    auto row_sum = std::accumulate(matrix[i].begin(), matrix[i].end(), 0ll);
    cout << row_sum << " ";
    }

    cout << endl;

    for (int j = 0; j < m; j++) {
        auto col_sum = 0ll;
        for (int i = 0; i < n; i++) {
            col_sum += matrix[i][j];
        }
        cout << col_sum << " ";
    }
    cout << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << elapsed.count() << endl;
    return 0;
}

