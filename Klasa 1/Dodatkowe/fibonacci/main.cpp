#include <iostream>

using namespace std;
unsigned long long n, a, b;

int main()
{
    cout << "Podaj numer wyrazu ciagu Fibonacciego: ";
    cin >> n;

    a = 0;
    b = 1;

    for (int i=1; i<=n-1; i++)
    {
        b = b+a;
        a = b-a;
    }

    cout << n << " wyraz ciagu Fibonacciego to: " << b;
    return 0;
}
