#include <iostream>
using namespace std;

int main()
{
    long long len, end[10000], fri[10000];
    int distr, fr_am;
    cin >> len >> distr >> fr_am;

    end[0]=0;
    end[distr]=len;
    for(int i=1; i<distr; i++){
        cin >> end[i];
    }
    
    for(int i=1; i<=fr_am; i++){
        cin >> fri[i];
    }

    for(int i=0; i<distr; i++){
        for(int j=1; j<=fr_am; j++){
            if(fri[j]>=end[i] && fri[j]<=end[i+1])
                cout << j << " ";
        }
        cout << "\n";
    }
}