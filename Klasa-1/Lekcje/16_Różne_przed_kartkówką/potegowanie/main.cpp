#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, a, b;
    unsigned long long x;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        x = pow(a, b);
        cout << x % 1000007 << "\n";
    }
}