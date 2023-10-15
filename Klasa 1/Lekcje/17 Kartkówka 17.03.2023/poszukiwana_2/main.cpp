#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q, a, x;
    cin >> n >> q;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < q; i++) {
        cin >> a;
        auto low = lower_bound(arr, arr + n, a);
        if (a > arr[n-1]) cout << "AAAAAAAAAAAAAAAAAA!11!!1!!\n";
        else x = *low ;
        for (int i = 0; i < n; i++){
            if (arr[i]==x) cout << x;
        }
    }

}