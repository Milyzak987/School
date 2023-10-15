#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    string zdania[151];
    int zlicz[125]{}, n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin>>ws;
        getline(cin, zdania[i]);
    }
        

    for(int j=0; j<n; j++)
    {
        int i=0;
        string x=zdania[j];
        for(int k=0; k<x.length(); k++)
        {   
            ++zlicz[(int)x[i]];
            ++i;
        }
    }

    for(int i='a';i<='z';i++)
    {
        if((int)zlicz[i]>0)
            cout<<(char)i<<" "<<zlicz[i]<<endl;
    }
                    
    for(int i='A';i<='Z';i++)
    {
        if((int)zlicz[i]>0)
        {
            cout<<(char)i<<" "<<zlicz[i]<<endl;   
        }
    }
    return 0;
}