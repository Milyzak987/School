#include <iostream>
using namespace std;

const long long MAXN = 507;
const long long MAXL = 2e5 + 7;
const long long INF = 2e18 + 7;

string names[MAXN];
long long dif[MAXN][MAXL];
long long col[MAXN] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, l;
    cin >> n >> l;
    for (long long i = 0; i < n; i++) {
        cin >> names[i];
    }

    for (long long i = 1; i < n; i++) {
        long long res = INF;
        for (long long j = l - 1; j >= 0; j--) {
            if (names[i - 1][j] < names[i][j]) {
                dif[i][j] = 1;
                res = 2;
            } else if (names[i - 1][j] > names[i][j]) {
                dif[i][j] = INF;
                res = 1;
            } else{
                dif[i][j] = res;
                res++;
            }
            col[j] = max(col[j], dif[i][j]);
        }
    }

    long long minx = INF, st = 0;
    for (long long i = 0; i < l; i++){
        if(col[i] < minx){
            minx = col[i];
            st = i;
        }
    }

    st++;
    minx--;
    cout << st << " " << st + minx;

    return 0;
}