#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool sortbysec(pair<long long, long long> &a, pair<long long, long long> &b) {
    return (a.second > b.second);
}
vector<pair<long long, long long>> heights(1000002);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        heights.push_back(make_pair(a * k + b, a));
    }

    sort(heights.begin(), heights.end(), greater<pair<long long, long long>>());
    sort(heights.begin(), heights.begin() + k, sortbysec);
    for (int i = 0; i < min(k, n); i++) {
        heights[i].first = i * heights[i].second;
    }

    cout << (*max_element(heights.begin(), heights.end())).first;
}