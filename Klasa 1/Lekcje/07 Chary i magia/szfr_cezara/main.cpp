#include<iostream>
#include<string>

using namespace std;

void szyfruj(int klucz, string &tab)
{		
	int pom;
	char a, z;
	
	for(int i = 0; i < tab.size(); i++)
	{
		int znak = tab[i];
		if((znak >= 'A' && znak <= 'Z') || (znak >= 'a' && znak <= 'z'))
		{
			if(znak >= 'a' && znak <= 'z') 
				a = 'a', z = 'z';
			else
				a = 'A', z = 'Z';
	
			if(klucz >= 0)
					
				if(tab[i] + klucz <= z)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz - 26; 
			else
				if(tab[i] + klucz >= a)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz + 26;
		}
	}
}

int main()
{
	string tab, type; 
	
	int klucz;
	getline(cin, type);
	cin>>klucz;
	getline(cin, tab);
	getline(cin, tab);
	
    if(type=="szyfruj")
        szyfruj(klucz,tab);
    else
        szyfruj(-klucz,tab);
	
	cout<<tab;
}