#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, n, tab[1000000];
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> tab[i];
	}
	sort(tab+a-1, tab+b);
	for (int i = 0; i < n; i++) {
		cout << tab[i] << " ";
	}
}