#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
int ilosc, i;
double w1, w2;
pair<int, int> pary[MAXN];

bool compare(pair<int, int> para1, pair<int, int> para2) {
    w1 = para1.first / pow(2, para1.second);
    w2 = para2.first / pow(2, para2.second);
    if (w1 == w2) {
        return para1.first < para2.first;
    }
    return w1 < w2;
}

int main() {
    cin >> ilosc;
    for (i = 0; i < ilosc; ++i) {
        cin >> pary[i].first >> pary[i].second;
    }
    sort(pary, pary + ilosc, compare);
    for (i = 0; i < ilosc; ++i) {
        cout << pary[i].first << ' ' << pary[i].second << "\n";
    }
}