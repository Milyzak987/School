#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 7;
vector<int> prices(MAXN);
vector<int> max_money(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        int money = 0;
        for (int j = i; j < n; j++) {
            int diff = prices[j] - prices[i];
            money = max(money, diff);
        }
        maxx = max(maxx, money);
    }
    cout << maxx;
}