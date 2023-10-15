#include <iostream>
using namespace std;

int n, a;
int w;
int m;


int main()
{
    cin >> n;
    cin >> a;
    w=a;
    m=a;
    for (int i=1; i<=n-1; i++)
    {
        cin >> a;
        if(a>w)
            w=a;
        if(a<m)
            m=a;

    }
    cout << w-m;
}
