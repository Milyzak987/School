#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int tab[100000], n, k, x=0, inne=-1;
    cin >> n >> k;
    for(int i=0; i<n; i++)
    {
        cin >> tab[i];
    }
    sort(tab, tab+n);
    for(int i=0; i<n; i++)
    {
        if(tab[i]%k!=inne){
            x++;
            inne=tab[i+1]%k;
        }
    }
    cout << x;
}