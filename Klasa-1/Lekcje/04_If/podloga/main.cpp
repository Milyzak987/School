#include <iostream>
using namespace std;

int i, a, b;

int main()
{
    cin >> i;
    a = i % 10;
    while (i > 0) {
        b = i % 10;
        i = i / 10;
    }
    cout << a*b;
}
