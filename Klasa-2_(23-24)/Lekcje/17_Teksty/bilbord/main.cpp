#include <iostream>
#include <string>
using namespace std;

bool stats1[200], stats2[200];

int canRepeat(string s) {
    int start = 0;
    int is = 1;
    int i = 1;
    int res = 0;
    while (is < s.length() && i < s.length()) {
        if (s[i] == s[start]) {
            start++;
            i++;
            res++;
        } else {
            start = 0;
            is++;
            i = is;
            res = 0;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    for (auto x : s1) {
        stats1[x] = true;
    }
    for (auto x : s2) {
        stats2[x] = true;
    }
    int c = canRepeat(s1);
    s1 = s1.erase(s1.length() - c, c);
    for (int i = 0; i < 200; i++) {
        if (!stats1[i] && stats2[i]) {
            cout << "INF";
            return 0;
        }
    }
    int res = 0;
    for (int i = 0; i < s2.length(); i++) {
        for (int j = 0; j < s1.length(); j++) {
            int x = s2[i];
            int y = s1[j];
            if (x == y) {
                i++;
            }
        }
        res++;
    }
    cout << res;
}