#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(int tab[], int n) {
  bool zamiana = true;

  while (zamiana) {
    zamiana = false;

    for (int i=0; i<n-1; i++) {
      if (tab[i] > tab[i+1]) {
        int tmp = tab[i];
        tab[i] = tab[i+1];
        tab[i+1] = tmp;

        zamiana = true;
      }
    }
  }
}

int main() {
  int tab[100], n;
  
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> tab[i];
  }


  bubble_sort(tab, n);

  for (int i = 0; i < n; i++) {
    cout << tab[i] << " ";
  }
  cout << endl;

  return 0;
}