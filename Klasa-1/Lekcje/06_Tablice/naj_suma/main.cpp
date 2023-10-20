#include <iostream>
using namespace std;

long long ilo_dni, wys, naj, odp=1;

main()
{
    //wpisywanie dni
    cin >> ilo_dni;
    long long dni[ilo_dni];
    for(int i=0; i<ilo_dni; i++)
        cin >> dni[i];


    //znajdowanie najwiekszej sumy
    wys=0;
    for(int i=0; i<ilo_dni; i++){
        wys+=dni[i];
        if(wys>=naj){
            naj=wys;
            odp=i+1;}
    }

    cout << odp;
}
