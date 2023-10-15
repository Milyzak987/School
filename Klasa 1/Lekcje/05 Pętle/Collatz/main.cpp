#include <iostream>
using namespace std;

int a;

int main() {

  cin >> a;
  while(a!=1)
    {
      cout << a << " ";
      if(a%2==0)
      {
        a/=2;
      }
      else{
        a*=3;
        a++;
      }
    }
  cout << "1";
    

}