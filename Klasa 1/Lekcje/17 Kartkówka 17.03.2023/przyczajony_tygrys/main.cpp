#include <iostream>
using namespace std;

int n, q, arrs[1000000] = {}, arrt[1000000] = {}, x, a, b, smoki, tygrysy;

int main() {
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==3) arrt[i]=1;
        if(x==4) arrs[i]=1;
    }
    for(int i=0; i<q; i++){
        cin >> a >> b;
        smoki = 0;
        tygrysy = 0;
        for(int j=a-1; j<b; j++){
            smoki+=arrs[j];
            tygrysy+=arrt[j];
        }
        cout << tygrysy << " " << smoki << "\n";
    }
}