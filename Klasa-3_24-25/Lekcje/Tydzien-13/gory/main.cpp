#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 7;
int heights[MAXN];
ll differences[MAXN];
ll upCost, downCost;

ll calculateCost(ll diff) {
    if (diff > 0) {
        return -diff * upCost;
    } else {
        return -diff * downCost;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numPoints, numQueries;
    cin >> numPoints >> numQueries >> upCost >> downCost;

    ll totalCost = 0;

    cin >> heights[0];

    for (int idx = 1; idx <= numPoints; idx++) {
        cin >> heights[idx];
        differences[idx] = heights[idx] - heights[idx - 1];
        totalCost += calculateCost(differences[idx]);
    }

    for (int query = 0; query < numQueries; query++) {
        int startPos, endPos, delta;
        cin >> startPos >> endPos >> delta;

        totalCost -= calculateCost(differences[startPos]);
        if (endPos + 1 <= numPoints) {
            totalCost -= calculateCost(differences[endPos + 1]);
        }

        differences[startPos] += delta;
        differences[endPos + 1] -= delta;

        totalCost += calculateCost(differences[startPos]);
        if (endPos + 1 <= numPoints) {
            totalCost += calculateCost(differences[endPos + 1]);
        }

        cout << totalCost << "\n";
    }

    return 0;
}