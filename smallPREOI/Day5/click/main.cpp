#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2007];
vector<bool> visited(2007);
vector<pair<int, int>> v(2007);
int n, s;

bool comp(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return (a.second < b.second);
}

void dfs(int x) {
    visited[x] = 1;
    for (auto u : graph[x]) {
        if (!visited[u]) dfs(u);
    }
}

bool solve(int s) {
    double mindis = 1e9;
    for(auto u : v){
        for(auto x : v){
            if(u == x) continue;
            double dis = sqrt(pow(abs(u.first - x.first), 2) + pow(abs(u.second - x.second), 2));
            mindis = min(mindis, dis);
        }
    }
}

double binsearch() {
    double l = 1, r = 1415000000, eps = 0.00001;
    double mid;

    while (r - l > eps) {
        mid = (l + r) / 2;
        if (solve(mid))
            r = mid;
        else
            l = mid;
    }
    return mid;
}

double easy() { 
    sort(v.begin(), v.begin() + n, comp);
    int maxx = 0;
    for (int i = 1; i < n; i++) {
        maxx = max(maxx, v[i].second - v[i - 1].second);
    }
    return (double)maxx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool ez = true;
    cin >> n;
    v[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first != 0) ez = false;
    }
    if (ez) { //just in case to have some points (maybe?)
        cout << fixed << setprecision(5) << easy() << "\n";
    } else {
        cout << fixed << setprecision(5) << binsearch() << "\n";
    }
}