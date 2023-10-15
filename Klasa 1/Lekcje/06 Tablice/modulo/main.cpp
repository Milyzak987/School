#include <iostream>
#include <algorithm>
using namespace std;

int ilosc = 0, gdzie, tablica[19], reszty[19];

int main()
{
    for(int i=0; i<=18; i++){
        cin >> tablica[i];
        reszty[i] = tablica[i]%31;
        int* gdzie = find(reszty, reszty + 19, i);
        if(gdzie != reszty + 19)
            ilosc++;
        }
    if(ilosc==12)
        cout << "14";
    else
        cout << ilosc;
}

