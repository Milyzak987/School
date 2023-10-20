#include <iostream>
using namespace std;

string ciag, win;

int main()
{
    cin >> ciag;
    win = ciag.substr(ciag.length() - 1);
    cout << win;
}
