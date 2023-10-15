#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 30007;
int bierki[MAXN], il_bierek, dl_bierki, p, k = 2, wyn, i;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> il_bierek;
    for (i = 0; i < il_bierek; ++i) cin >> bierki[i];
    sort(bierki, bierki + il_bierek);
    while (p < il_bierek) {
        while ((bierki[p] + bierki[p + 1] > bierki[k + 1]) && (k < il_bierek - 1)) k++;
        wyn = max(k - p + 1, wyn);
        ++p;
    }
    cout << wyn << "\n";
}