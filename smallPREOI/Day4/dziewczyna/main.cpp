#include <iostream>
#include <algorithm>
using namespace std;

const long long MAXN = 1e6 + 7;
const long long Pv = 127;
const long long MOD = 1e9 + 7;
long long P[MAXN], hash1[MAXN], hash2[MAXN];

void createHash(long long n, string str1, string str2) {
    P[0] = 1;
    for (long long i = 1; i <= n; i++) P[i] = (P[i - 1] * Pv) % MOD;
    for (long long i = 1; i <= n; i++) {
        hash1[i] = (hash1[i - 1] + P[i] * str1[i]) % MOD;
        hash2[i] = (hash2[i - 1] + P[i] * str2[i]) % MOD;
    }
}

long long calHash1(long long left, long long right, long long n) {
    long long result = (hash1[right] - hash1[left - 1] + MOD) % MOD;
    return ((long long)result * P[n - left + 1]) % MOD;
}

long long CalHash2(long long left, long long right, long long n) {
    long long result = (hash2[right] - hash2[left - 1] + MOD) % MOD;
    return ((long long)result * P[n - left + 1]) % MOD;
}

long long binsearch(long long n){
    long long rightEnd = n - 1, result = 0;
    for (long long i = 1; i < n; i++) {
        long long leftStart = 0, rightStart = min(i, rightEnd);
        while (leftStart < rightStart) {
            long long mid = (leftStart + rightStart) / 2;
            if (calHash1(i - mid, i + mid, n) == CalHash2(rightEnd - mid, rightEnd + mid, n))
                leftStart = mid + 1;
            else
                rightStart = mid;
        }
        result += leftStart;
        rightEnd--;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    string s1, s2;
    cin >> n >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for (long long i = 1; i <= n; i++)
        s2[i] = (s2[i] == '1') ? '0' : '1';

    createHash(n, s1, s2);
    cout << binsearch(n);
}
