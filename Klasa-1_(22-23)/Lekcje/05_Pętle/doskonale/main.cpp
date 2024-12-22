#include <iostream>
#include <cmath>
using namespace std;

int x;

int main()
{
    int n;
    cin >> n;
	int s = 1, p = sqrt(n);
	for(int i=2; i<=p; i++)
		if(n%i == 0)
			s+= i + n/i;
	if(n == p*p) s-=p;
	if(n == s)
	{
        cout << "TAK";
	}
    else
        cout << s;
}
