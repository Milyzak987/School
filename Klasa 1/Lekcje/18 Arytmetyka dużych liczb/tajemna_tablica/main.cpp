#include <iostream>
#include "tajtabbibl.h"
using namespace std;

int low = 1000000000, high = -1000000000, low_i, high_i;

void wyszukaj(int i){
    int P = 1000000000;
    int L = -1000000000;
    int sr;

    while(L<=P){
        sr = (L+P)/2;

        if(wieksze(i, sr) && !wieksze(i, sr + 1)) break;

        if(wieksze(i, sr))  L = sr + 1;
        else  P = sr - 1;
    }
    if((sr + 1) > high){
        high_i = i;
        high = sr+1;
    }
    if((sr + 1) < low){
        low_i = i;
        low = sr+1;
    }
}


int main() {
    int n = inicjuj();
    for(int i=0; i<n; i++){
        wyszukaj(i);
    }
    odpowiedz(low_i, high_i);
}