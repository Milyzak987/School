#include <iostream>
using namespace std;

bool czy_pierwsza(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return false;
	return true;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a, b, licz=0;
        cin >> a >> b;
        for(int i=a; i<=b; i++){
            if(czy_pierwsza(i))
                licz++;
        }
        cout << licz << endl;
    }
}