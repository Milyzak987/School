#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    pair <int, int> pairs[100001];
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> pairs[j].first;
            cin >> pairs[j].second;
        }
        sort(pairs, pairs + n);
        int ost = 0;
        for(int j=0; j<n; j++){
            if(ost>pairs[j].first){
                cout << "NIE\n";
                break;
            }
            ost=pairs[j].second;
            if(j == n-1){
                cout << "TAK\n";    
            }
        }
    }
}