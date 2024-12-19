#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<long long, int> minimalCostForDimension(const vector<int>& weights, int length) {
    vector<long long> prefixSum(length + 1, 0), weightedSum(length + 1, 0);

    for (int i = 1; i <= length; ++i) {
        prefixSum[i] = prefixSum[i - 1] + weights[i - 1];
        weightedSum[i] = weightedSum[i - 1] + weights[i - 1] * i;
    }

    long long minCost = LLONG_MAX;
    int bestPosition = 0;

    for (int pos = 0; pos <= length; ++pos) {
        long long leftSum = prefixSum[pos] * pos - weightedSum[pos];
        long long rightSum = (weightedSum[length] - weightedSum[pos]) - (prefixSum[length] - prefixSum[pos]) * pos;
        long long cost = leftSum + rightSum;

        if (cost < minCost) {
            minCost = cost;
            bestPosition = pos;
        }
    }

    return {minCost, bestPosition};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> c(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    vector<int> rowWeights(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rowWeights[i] += c[i][j];
        }
    }

    vector<int> colWeights(m, 0);
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            colWeights[j] += c[i][j];
        }
    }

    auto [rowCost, bestRow] = minimalCostForDimension(rowWeights, n);

    auto [colCost, bestCol] = minimalCostForDimension(colWeights, m);

    cout << rowCost + colCost << endl;
    cout << bestRow << " " << bestCol << endl;

    return 0;
}