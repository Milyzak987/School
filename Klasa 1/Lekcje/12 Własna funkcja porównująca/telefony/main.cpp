#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    pair <int, int> num[n];

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;

        num[i].second = x;
        string napis = to_string(x);

        char a = napis[1];
        napis[1] = napis[3];
        napis[3] = a;
        num[i].first = stoi(napis);
    }

    sort(num, num+n);

    for (int i=0; i<n; i++) {
        cout << num[i].second << ' ';
    }
}