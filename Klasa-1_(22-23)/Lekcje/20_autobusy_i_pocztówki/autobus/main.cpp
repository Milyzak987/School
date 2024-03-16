#include <iostream>
using namespace std;

int n, k, d;

int main(){
    cin >> d;
    for (int i=0; i<d; i++){
        cin >> n >> k;
        if(k==n-1) cout << n << endl;
        else cout << n-1 << endl;
    }
}