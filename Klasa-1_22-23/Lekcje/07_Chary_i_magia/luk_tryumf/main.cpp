#include <iostream>
#include <string>
using namespace std;

string x;
int main() {
  getline(cin, x);
  for (int i = 0; i < x.length(); i++) {
    if (x[i] == 117 || x[i] == 85) {
      cout << (char)(86);
    } else if (x[i] >= 97 && x[i] <= 122) {
      cout << (char)(x[i] - 32);
    } else if (x[i] >= 65 && x[i] <= 90) {
      cout << (char)(x[i]);
    }
  }
}