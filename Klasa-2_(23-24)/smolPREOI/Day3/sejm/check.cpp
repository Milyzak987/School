#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, a;
    cin >> x;
    for (int i = 0; i < x*2; i++) cin >> a;

    int n;
    cin >> n;
    if (n == -1) {
        cout << "I źli kłamcy";
    } else if (n == -2) {
        cout << "I zła ilość kłamców";
    } else if (n == 1) {
        cout << "C\n";
    }
}
