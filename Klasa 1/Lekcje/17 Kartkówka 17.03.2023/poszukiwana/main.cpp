#include <iostream>
#include <set>
using namespace std;

set<int> x;

int main(){

    int n, q, t;
    cin >> n >> q;

    for(int i=0;i<n;++i){
        cin >> t;
        x.insert(t);
    }
    for(int i=0;i<q;++i){
        cin >> t;
        auto xdd = x.lower_bound(t);

        if(xdd == x.end()) cout << "AAAAAAAAAAAAAAAAAA!11!!1!!" << "\n";
        else cout << *xdd << "\n";
    }
}