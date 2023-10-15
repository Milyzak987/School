#include <iostream>
using namespace std;

int a, b, r, i;

int sprawdz (int i) {

    while (i > 0) {
        r = i % 10;
        if ( r == 7)
            return 1;
        i = i / 10;
    }

 return 0;
}

int main()
{
    cin >> a;
    cin >> b;
    for(i=a; i<=b; i++)
    {
        if(i%7==0 || sprawdz(i)==1)
            cout << "plum" << endl;
        else
            cout << i << endl;
    }
}
