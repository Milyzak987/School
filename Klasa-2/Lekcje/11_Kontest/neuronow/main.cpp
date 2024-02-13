#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 7;
vector<int> power_plants(MAXN);
vector<vector<pair<int, int>>> graph(MAXN, vector<pair<int, int>>(0));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int e, d, k;
    cin >> e >> d >> k;
    for (int i = 1; i <= e; i++) {
        cin >> power_plants[i];
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    if (d == 1) {
        int mini, minx = 1e9 + 7; 
        for (int i = 1; i <= e; i++) {
            if (graph[i][0].second < minx) {
                minx = graph[i][0].second;
                mini = i;
            }
        }
        cout << mini;
    } else {
        cout << "-";
    }
}