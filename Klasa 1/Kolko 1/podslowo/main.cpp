#include <iostream>

using namespace std;

string slowo;
int  zlicz = 0, naj = 0;

int main()
{
    cin >> slowo;
    for (int i = 0; i < slowo.length(); i++)
    {
        if(slowo[i]=='a')
            zlicz += 1;
        else
         {
            if(zlicz>naj)
                naj = zlicz;
            zlicz = 0;
         }
    }
    if(zlicz>naj)
        naj = zlicz;
    if (naj==0)
    {
        cout << "BRAK";
    }
    else
    {
        for(int i=0; i<naj; i++)
        {
            cout << 'a';
        }
    }
}
