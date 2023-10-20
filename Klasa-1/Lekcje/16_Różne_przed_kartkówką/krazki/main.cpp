#include <iostream>
using namespace std;

int n, m, rur[300000], kra[300000], x=0, wyn;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> rur[i];
    }
    for(int i=0; i<m; i++){
        cin >> kra[i];
        while(kra[i]<=rur[x]){
            x++;
        }
        x--;
        rur[x]=0;
        wyn=x;
        x=0;
    }
    cout << wyn+1;
}