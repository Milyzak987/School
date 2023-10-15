#include <iostream>
using namespace std;

int il_tekstow;
int il_liter[200];
string tekst;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> il_tekstow;
    for (int i = 0; i < il_tekstow; i++) {
        cin >> ws;
        getline(cin, tekst);
        for (size_t i = 0; i < tekst.length(); i++)
            if (!isspace(tekst[i])) il_liter[(int)tekst[i]]++;
    }
    for (int i = 97; i < 123; i++)
        if (il_liter[i] > 0) cout << (char)i << " " << il_liter[i] << "\n";
    for (int i = 65; i < 91; i++)
        if (il_liter[i] > 0) cout << (char)i << " " << il_liter[i] << "\n";

    return 0;
}