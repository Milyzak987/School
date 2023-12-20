#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> vecX(200007);
vector<int> vecY(200007);
map<int, int> statsX = {};
map<int, int> statsY = {};

bool compX(int &a, int &b) {
    if (statsX[a] == statsX[b]) {
        return a < b;
    } else {
        return statsX[a] > statsX[b];
    }
}
bool compY(int &a, int &b) {
    if (statsY[a] == statsY[b]) {
        return a < b;
    } else {
        return statsY[a] > statsY[b];
    }
}

int solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> vecX[i];
        statsX[vecX[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> vecY[i];
        statsY[vecY[i]]++;
    }

    sort(vecX.begin(), vecX.end(), compX);
    sort(vecY.begin(), vecY.end(), compY);

    int res = 0;
    for (int i = 0; i < k; i++) {
        if (statsX[vecX[i]] > statsY[vecY[i]]) {
            res += statsX[vecX[i]];
            statsX[vecX[i]] = 0;
            statsY[vecY[i]]--;
            // while(vecX[i] == vecX[i+1]) i++;
        } else {
            res += statsY[vecY[i]];
            statsX[vecX[i]]--;
            statsY[vecY[i]] = 0;
            // while(vecY[i] == vecY[i+1]) i++
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
}