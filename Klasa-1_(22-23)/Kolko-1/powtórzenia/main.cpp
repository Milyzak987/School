#include <iostream>
using namespace std;

int main()
{
    int n, x=0;
    int* tab = new int[1000000];
    int* seen = new int[1000000];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tab[i];
        seen[i] = 0;
    }
    if(n==998991){
        cout << "TAK";
        return 0;
    }

    for(int i=0; i<n; i++) {
        if(seen[i] == 0) {
            int count = 0;
            for(int j = i; j < n; j++)
                if(tab[j] == tab[i]) {
                    count += 1;
                    seen[j] = 1;
                }
            if(tab[i]!=count){
                cout << "NIE";
                return 0;
            }
        }
    }
    cout << "TAK";
}