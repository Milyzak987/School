#include <iostream>
using namespace std;

int letters_a[123] = {}, letters_b[123] = {};

void zlicz(int *letters, string word)
{
    int i=0;
    for(int k=0; k<word.length(); k++)
    {   
        ++letters[i];
        ++i;
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    zlicz(letters_a, a);
    zlicz(letters_b, b);
    for(int i=0; i<a.length(); i++){
        int x = (int)a[i];
        if(letters_a[x]>0){
            cout << (char)x;
            letters_a[x]--;
        }
    }
}