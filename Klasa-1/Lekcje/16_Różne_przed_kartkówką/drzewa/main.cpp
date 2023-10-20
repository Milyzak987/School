#include <iostream>
using namespace std;

int main()
{
    string ciag;
    int n, a, b, wynik;
    cin >> ciag;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        for(int j=a; j<=b; j++){
            if(ciag[j] == 'b') wynik++;
        }
        cout << wynik;
    }
}
