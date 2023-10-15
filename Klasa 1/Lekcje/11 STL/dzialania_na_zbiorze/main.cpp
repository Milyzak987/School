#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int m;
    long long x;
    char znak;
    set<long long> zbior;
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> znak;
        if(znak == '+'){
            cin >> x;
            zbior.insert(x);
        }
        if(znak == '-'){
            cin >> x;
            zbior.erase(x);
        }
        if(znak == 'f'){
            cin >> x;
            auto wieksza = zbior.lower_bound(x);
            if (wieksza != zbior.end()) {
                cout << *wieksza << "\n";
            } else {
                cout << "BRAK\n";
            }
        }
        if(znak == 's'){
            cout << zbior.size();
            cout << endl;
        }
        if(znak == 'w'){
            for(auto it=zbior.begin(); it!=zbior.end(); it++){
                long long val = *it;
                cout << val << ' ';
            }
            cout << endl;
        }
    }
}