#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;
typedef long long ll;

const int MAXN = 1007;
const int MAXK = 40007;
int arr[MAXN];
pair<int, int> ans[MAXK];

bool asc(int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
    }
    return true;
}

bool desc(int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mt19937_64 rng(2137);

    int n, p;
    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int j = 0;
    if (p == 1) {
        while (!asc(n) && j < 40000) {
            int a = uniform_int_distribution<int>(0, n - 2)(rng);
            int b = a + 1;
            if (uniform_int_distribution<int>(0, 1)(rng) == 1) {
                swap(a, b);
            }
            arr[a] = arr[a] ^ arr[b];
            ans[j].first = a + 1;
            ans[j].second = b + 1;
            j++;
        }
    } else {
            while (!desc(n) && j < 40000) {
            int a = uniform_int_distribution<int>(0, n - 2)(rng);
            int b = a + 1;
            if (uniform_int_distribution<int>(0, 1)(rng) == 1) {
                swap(a, b);
            }
            arr[a] = arr[a] ^ arr[b];
            ans[j].first = a + 1;
            ans[j].second = b + 1;
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // cout << j << "\n";
    // for (int i = 0; i < j; i++) {
    //     cout << ans[i].first << " " << ans[i].second << "\n";
    // }

    return 0;
}