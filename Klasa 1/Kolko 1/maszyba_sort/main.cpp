#include<iostream>
#include<algorithm>
using namespace std;

bool porownaj(int a, int b)
{
	return a>b;
}

int main()
{
	int n, q, a, b;
    int seq[5001];
    char x;
	cin >> n >> q;

    for (int i=0; i<n; i++)
    {
        cin >> seq[i];
    }

    for (int i=0; i<q; i++)
    {
        cin >> a >> b >> x;
        a--;
        if(x=='R')
        {
            sort(seq+a, seq+b);
        }
        else
        {
            sort(seq+a, seq+b, porownaj);
        }
    }
        for (int i=0; i<n; i++)
    {
        cout << seq[i] << " ";
    }
}