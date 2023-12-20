#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> posY(2007);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    posY[0] = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        posY[i] = b;
    }
    sort(posY.begin(), posY.begin()+n);
    int maxx = 0;
    for(int i = 1; i < n; i++){
        maxx = max(maxx, posY[i] - posY[i-1]);
    }
    cout << fixed << setprecision(5) << (double)maxx << "\n";
}
