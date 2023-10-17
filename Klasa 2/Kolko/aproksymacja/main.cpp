#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    double l = 0, r = 2000002;
    for (int i = 0; i < n; i++) {
        int mid = (l + r) / 2;

        if (f(mid) == 1)
            r = mid;
        else
            l = mid;
    }
    
}