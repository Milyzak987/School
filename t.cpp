#include <iostream>
#include <string>
using namespace std;

bool czyOdwrotnosc(string s) {
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string ciag;
    cout << "Podaj ciąg liczb 0 i 1: ";
    cin >> ciag;

    if (czyOdwrotnosc(ciag)) {
        cout << "Jest to odwrotność swojego przedziału." << endl;
    } else {
        cout << "Nie jest to odwrotność swojego przedziału." << endl;
    }

    return 0;
}
