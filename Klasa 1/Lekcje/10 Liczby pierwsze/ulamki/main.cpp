#include <iostream>
using namespace std;

int gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    long long n, a, b, c, d;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c >> d;
        if(b==d){
            a+=c;
            cout << a / gcd(a, b) << " " << b / gcd(a, b) << "\n";
        } else {
            a*=d;
            c*=b;
            b*=d;
            a+=c;
            cout << a / gcd(a, b) << " " << b / gcd(a, b) << "\n";
        }

    }
}
