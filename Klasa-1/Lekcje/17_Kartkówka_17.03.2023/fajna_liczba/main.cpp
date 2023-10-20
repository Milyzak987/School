#include <iostream>

using namespace std;

int ciag[3002], n;

string gasienica(int n){
    int wyn = 1000000010, glowa = 0, ogon = 1, akt_sum = 0;
    while(glowa < n){
        glowa++;
        akt_sum += ciag[glowa];
        if(akt_sum < 2137){
            continue;
        }
        if(akt_sum == 2137){
            return "TAK";
        }
        while(ogon < glowa && akt_sum >= 2137){
            akt_sum -= ciag[ogon];
            ogon++;
            if(akt_sum == 2137){
                return "TAK";
            }
        }
    }
return "NIE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ciag[i];
    }
    cout << gasienica(n);
}