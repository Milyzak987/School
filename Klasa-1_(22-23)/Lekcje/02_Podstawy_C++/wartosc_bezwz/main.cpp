#include <iostream>

using namespace std;

int x;

int main()
{
    cin >> x;
    if(x>=0)
        cout << x ;
    else
    {
        x=x-(2*x);
        cout << x ;
    }


}
