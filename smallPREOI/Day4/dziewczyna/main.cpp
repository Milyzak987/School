#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MAXN = 507;

vector<vector<int>> board(MAXN, vector<int>(MAXN, 0));
string s;

bool czyOdwrotnosc(int start, int end) {
    int len = end - start + 1;
    for (int i = start; i < start + (len / 2); ++i) {
        if (s[i] == s[end + start - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, res = 0;
    cin >> n;
    cin >> s;

    int k = 0;
    for (int i = 1; i < n; i++) {
        if ((int)s[i] != (int)s[k]) {
            res++;
            int a = k - 1, b = i + 1;
            while (czyOdwrotnosc(a, b) && a >= 0 && b < n) {
                res++;
                a--;
                b++;
            }
        }
        k++;
    }
    cout << res;
    return 0;
}