#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1007;

vector<long long> lengthA(MAXN);
vector<long long> lengthB(MAXN);
vector<long long> areas(MAXN* MAXN);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, n, k;
    cin >> a >> b >> n >> k;

    long long curr = 0, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        lengthA[i] = x - curr;
        curr += x - curr;
    }
    lengthA[n] = a - x;

    curr = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        lengthB[i] = x - curr;
        curr += x - curr;
    }
    lengthB[n] = b - x;

    long long y = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            areas[y] = lengthA[i] * lengthB[j];
            y++;
        }
    }
    sort(areas.begin(), areas.begin() + (n + 1) * (n + 1), greater());
    cout << areas[k - 1];
}