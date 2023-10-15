#include <iostream>
using namespace std;

int kartki, dlugosci[20], wartosci[20][1000];

int main()
{
    cin >> kartki;
    for (int i=0; i<kartki; i++)
    {
        cin >> dlugosci[i];
        for (int j=0; j<dlugosci[i]; j++)
            {
                cin >> wartosci[i][j];
            }
    }
    for (int i=0; i<kartki; i++)
    {
       for (int j=1; j<dlugosci[i]; j+=2)
            {
                cout << wartosci[i][j] << " ";
            }
        for (int j=0; j<dlugosci[i]; j+=2)
            {
                cout << wartosci[i][j] << " ";
            }
        cout << "\n";
    }

}
