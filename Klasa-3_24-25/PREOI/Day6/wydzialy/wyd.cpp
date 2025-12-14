#include "wydlib.h"
#include <vector>
#include <array>
#include <limits>

using namespace std;

constexpr int K = 7;
constexpr int INF = numeric_limits<int>::max();

vector<vector<int>> Bitek(int n, array<int, K> A, array<int, K> B) {
    vector<vector<int>> grid(n, vector<int>(n, INF));
    
    for (int i = 0; i < K; i++) {
        grid[A[i]][B[i]] = i + 1;
    }
    
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid[i][j] == INF) {
                grid[i][j] = 12;
            }
        }
    }
    
    return grid;
}

array<int, K> Bajtazar(array<int, 9> A) {
    array<int, K> actions;
    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};
    
    for (int i = 0; i < K; i++) {
        int min_val = INF;
        int best_move = 4;
        for (int j = 0; j < 5; j++) {
            if (A[j + 1] < min_val) {
                min_val = A[j + 1];
                best_move = j;
            }
        }
        actions[i] = best_move;
    }
    
    return actions;
}
