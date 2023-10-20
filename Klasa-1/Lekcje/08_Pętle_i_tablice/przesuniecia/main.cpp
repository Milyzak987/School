#include<iostream>
using namespace std;

int main(){
    int n, k, tab[10000];
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> tab[i];
    }
    for(int i=k; i<n+k; i++){
        cout << tab[i%n] << " ";
    }
}