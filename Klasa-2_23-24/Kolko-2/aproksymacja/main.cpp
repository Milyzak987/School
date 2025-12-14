#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000002;
vector<int> v(MAXN);

bool res(double x, int n) {
    double a = v[0] - x, mx;
    for (int i = 1; i < n; i++) {
        double b = v[i] - x;
        mx = v[i] + x;
        if (a > mx)
            return false;
        else a = max(a, b);
    }
    return true;
}

void num(double x, int n) {
    double a = v[0] - x;
    cout << a << endl;
    for (int i = 1; i < n; ++i) {
        double b = v[i] - x;
        a = max(a, b);
        cout << a << endl;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double l = 0, r = 2000002;
    while (r - l > 0.0001) {
        double mid = (l + r) / 2;
        if (res(mid, n))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(4) << l << endl;
    num(l, n);
}