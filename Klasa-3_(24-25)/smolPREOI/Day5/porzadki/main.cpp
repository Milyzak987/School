#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int MAXN = 1007;
int arr[MAXN];
deque<pair<int, int>> ans;

void XORsort(int n) {
    bool swapped = true;

    while(swapped) {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                arr[i] = arr[i] ^ arr[i + 1];
                ans.push_back({i + 1, i + 2});
                arr[i + 1] = arr[i] ^ arr[i + 1];
                ans.push_back({i + 2, i + 1});
                arr[i] = arr[i] ^ arr[i + 1];
                ans.push_back({i + 1, i + 2});
                swapped = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    XORsort(n);

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";

    int k = ans.size();
    cout << k << "\n";
    // for (int i = 0; i < k; i++) {
    //     cout << ans[i].first << " " << ans[i].second << "\n";
    // }

    return 0;
}