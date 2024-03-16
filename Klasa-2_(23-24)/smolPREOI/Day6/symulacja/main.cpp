#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k, n, p;
    cin >> k >> n >> p;

    if (k == 0 && n == 0) {
        cout << "0 0 1";
    } else if (n == 0 && p == 0) {
        cout << "1 0 0";
    } else if (k == 0 && p == 0) {
        cout << "0 1 0";
    } else if (k == 0) {
        cout << "0 1 0";
    } else if (n == 0) {
        cout << "0 0 1";
    } else if (p == 0) {
        cout << "1 0 0";
    }

    return 0;
}