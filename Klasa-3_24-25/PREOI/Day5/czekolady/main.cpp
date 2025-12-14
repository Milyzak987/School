#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int INF = 2e9;
const int MAXN = 407;
bool frend[MAXN];
vector<int> choco(MAXN);
vector<int> temp(MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            frend[i] = true;
        }
    }

    int res = INF;
    for (int i = 1; i <= n; i++) {
        int curLeft = x, curRes = 0;
        for (int ii = 0; ii < i; ii++) {
            temp[ii] = curLeft / (i - ii) + (curLeft % (i - ii) != 0);
            if (frend[ii]) {
                curRes += temp[ii];
            }
            curLeft -= temp[ii];
        }
        if(curRes < res){
            choco = temp;
            res = curRes;
        }
    }
    cout << res << "\n";
    for(int i = 0; i < n; i++){
        cout << choco[i] << " ";
    }
}