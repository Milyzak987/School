#include <iostream>

using namespace std;

int onleft[30000];
bool checked[30000];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> onleft[i];
  }

  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (checked[i] == false) {
      int index = i;
      while (checked[index] == false) {
        checked[index] = true;
        index = onleft[index];
      }
      x++;
    }
  }

  cout << x;
  return 0;
}