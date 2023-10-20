#include <iostream>
using namespace std;

int main()
{
    int n, x=0;
    long long a[100000];
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
        for(int i=0; i<n; i++)
    {
        a[i]/=10;
        if((a[i]%10)==0 && a[i]!=0)
        {
            x++;
        }
    }
    cout << x;
}