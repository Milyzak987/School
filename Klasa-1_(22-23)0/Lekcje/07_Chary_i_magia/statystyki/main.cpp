#include <iostream>
using namespace std;

void spaces(string text)
{
    int x=0;
    for(int i=0; i<text.length(); i++)
    {
        if(text[i]==' ')
            x++;
    }
    cout << x << ' ';
}
void numbers(string text)
{
    int x=0;
    for(int i=0; i<text.length(); i++)
    {
        if(text[i]>='0' && text[i]<='9')
        {
            x++;
            while(text[i]>='0' && text[i]<='9')
            {
                i++;
            }
        }
    }
    cout << x << ' ';
}
void words(string text)
{
    int x=0;
    for(int i=0; i<text.length(); i++)
    {
        if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z'))
        {
            x++;
            while((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z'))
            {
                i++;
            }
        }
    }
    cout << x << ' ';
}
void sentences(string text)
{
    int x=1;
    for(int i=0; i<text.length(); i++)
    {
        if(text[i]=='.' && text[i+1]!='.' && text[i+1]!=0 && text[i-1]!=0 && text[i-1]!='.') x++;
        else if(text[i]=='.' && text.length()==1) x=0;
    }
    cout << x << ' ';
}
void palindroms(string text)
{
    int x=0, l=0, sta=0;
    char word[1000000];
    for(int i=0; i<text.length(); i++)
    {
        if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z'))
        {
            l=0;
            sta=0;
            while((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z'))
            {
                word[l]=text[i];
                i++;
                l++;
            }
            int end=l-1;
            while(sta<=end)
            {
                if(word[sta]==word[end] || word[sta]==word[end]+32 || word[sta]==word[end]-32)
                {
                    sta++;
                    end--;
                }
                else
                {
                    x--;
                    break;
                }
            }
            x++;
        }
    }
    cout << x << ' ';
}

int main()
{
    short n, stat[5];
    string text;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> stat[i];
    }
    getline(cin, text);
    getline(cin, text);
    for(int i=0; i<n; i++)
    {
        if(stat[i]==1){
            spaces(text);
        }
        if(stat[i]==2){
            numbers(text);
        }
        if(stat[i]==3){
            words(text);
        }
        if(stat[i]==4){
            sentences(text);
        }
        if(stat[i]==5){
            palindroms(text);
        }
    }
}