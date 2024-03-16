#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 7;
vector<int> v(MAXN), pref(MAXN);
stack<int> s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string str;
    cin >> n >> k;
    cin >> str;
    str = ' ' + str;
    for (int i = 1; i <= n; i++) {
        if (str[i] == 'b')
            v[i] = -1;
        else
            v[i] = k;
        pref[i] = pref[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++) {
        s1.push(i);
        pref[s1.size()] = pref[s1.size() - 1] + v[i];
        if (s1.size() >= k + 1 && i >= k && pref[s1.size()] == pref[s1.size() - k - 1]) {
            for (int j = 1; j <= k + 1; j++) {
                if (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
    }
    for (int i = 1; i <= n / (k + 1); i++) {
        for (int j = 0; j <= k; ++j) {
            if (!s2.empty()) {
                cout << s2.top() << " ";
                s2.pop();
            }
        }
        cout << "\n";
    }
}