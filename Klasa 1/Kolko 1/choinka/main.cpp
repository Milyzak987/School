#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
   
   
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n - i + 1; j++ )
        {
            cout << " ";
        }
        for( int j = 1; j <= i * 2 - 1; j++ )
        {
            cout << "*";
        }
        cout << endl;
    }
    for( int i = 1; i <= n+1; i++ )
    {
        for( int j = 1; j <= n+1 - i; j++ )
        {
            cout << " ";
        }
        for( int j = 1; j <= i * 2 - 1; j++ )
        {
            cout << "*";
        }
        cout << endl;
    }
   
   
    for( int pien = 1; pien <= 2; pien++ )
    {
        for( int pien = 1; pien <= n; pien++ )
        {
            cout << " ";
        }
        cout << "*\n";
    }
   
    return 0;
}