#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> vecX(200007);
vector<int> vecY(200007);
map<int, int> stats = {};

int solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> vecX[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vecY[i];
        stats[vecY[i]]++;
    }

    for (auto u : stats){
        
        m.find("f") == m.end()
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
}