#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n, k, a;
        cin >> n >> k;
        for (int j = 0; j < n; j++) cin >> a;
        long long ans = n * k + 1;
        cout << ans << "\n";
    }
    return 0;
}