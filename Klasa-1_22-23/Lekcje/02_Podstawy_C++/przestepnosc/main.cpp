#include <iostream>
using namespace std;

int main()
{
    int r;
    cin >> r;
    if (r%4 == 0 and r%100 != 0 or r%400 == 0)
    {
        cout << "TAK";
    } else
    {
        cout << "NIE";
    }
}
