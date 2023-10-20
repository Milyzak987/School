#include <iostream>
using namespace std;

int a;

int main()
{
    cin >> a;
    for (int i=a; i>=1; i--)
        if (a%i==0)
        {
            cout << i << endl;
        }
}
