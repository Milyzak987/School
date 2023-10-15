#include <iostream>
using namespace std;

int main()
{
    int n, i=1;
    cin >> n;
    while((n%i)!=0)
    {
        i++;
    }
    if((n/i)>i)
        cout << i << " " << n/i;
    else
        cout << n/i << " " << i;
}