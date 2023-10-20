#include <iostream>
#include <cstring>
using namespace std;

bool sprawdz(char *sl1, char *sl2){
  int dl1 = strlen(sl1), dl2 = strlen(sl2);
  if(dl1!=dl2)return false;
  
  int licz[200] ={};
  for(int i=0;i<dl1;i++)
  		licz[sl1[i]]++; 
  	for(int i=0;i<dl1;i++)
  		licz[sl2[i]]--; 
  		
  	for(int i=0;i<127;i++)
  		if(licz[i]!=0) 
			return false; 
  return true;
  }

int main() {
  char sl1[201], sl2[201];
  cin>>sl1>>sl2;
  if(sprawdz(sl1,sl2))
     cout<<"TAK";
   else
     cout<<"NIE";
  
  return 0;
  }