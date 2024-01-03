#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 200007;
vector<long long> lengthA(MAXN), lengthB(MAXN);
long long n, k;

long long solve(long long x) {
    long long res = 0, a = 0;
    for (int b = n - 1; b >= 0; b--) {
        while (a < n && lengthA[a] * lengthB[b] < x) a++;
        res += n - a;
    }
    return res;
}

void binsearch() {
    long long l = lengthA[0] * lengthB[0], r = lengthA[n - 1] * lengthB[n - 1];
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (solve(mid) >= k) l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
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

    n++;
    sort(lengthA.begin(), lengthA.begin() + n);
    sort(lengthB.begin(), lengthB.begin() + n);

    binsearch();
}