#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;
        while (!s.empty() && h < s.top()) {
            s.pop();
        }
        if (s.empty() || s.top() < h) {
            s.push(h);
            res++;
        }
    }
    cout << res;
}