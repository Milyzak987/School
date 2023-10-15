#include <iostream>
using namespace std;

int n, a[1000000], x=0;

void wsuwanie(int a[], int n, int x){
    for(int i=1; i<n; i++){
        if(a[i]>a[i+1]){
            a[i]=a[i-1]+1;
            x++;
        }
    }
    for(int i=1; i<n; i++){
        if(a[i]>a[i+1]){
            cout << -1;
            return;
        }
    }
    cout << x;
}

int main()
{
    a[0]=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    wsuwanie(a, n, x);
}