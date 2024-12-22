#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;
vector<vector<char>> grid(507, vector<char>(507));
vector<vector<long long>> dp(507, vector<long long>(507, 0));
vector<vector<long long>> pref(507, vector<long long>(507, 0));

int main() {
    long long a, b, k, z;
    cin >> a >> b >> k >> z;
    for (long long i = 0; i < a; i++) {
        for (long long j = 0; j < b; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') dp[i][j] = 1;
        }
    }

    long long x = 0, temp = 0;
    while (x != k) {
        for (long long i = 0; i < a; i++) {
            pref[i][0] = 0;
            for (long long j = 0; j < b; j++) {
                pref[i][j + 1] = pref[i][j] + dp[i][j];
            }
        }
        for (long long i = 0; i < a; i++) {
            for (long long j = 0; j < b; j++) {
                if (grid[i][j] != '#') {
                    for (long long l = 0; l <= (2 * z); l++) {
                        long long n = i - z + l;
                        long long e, f;
                        if (l < z) {
                            e = j - l;
                            f = j + l;
                        } else {
                            e = j - (2 * z - l);
                            f = j + (2 * z - l);
                        }
                        if (n < 0 || n >= a) continue;
                        if (e < 0) e = 0;
                        if (e >= b) e = b - 1;
                        if (f < 0) f = 0;
                        if (f >= b) f = b - 1;
                        temp = (temp + pref[n][f + 1] - pref[n][e]) % MOD;
                    }
                    dp[i][j] = temp;
                    temp = 0;
                }
            }
        }
        x++;
    }

    for (long long i = 0; i < a; i++) {
        for (long long j = 0; j < b; j++) {
            if (grid[i][j] == '#')
                cout << -1 << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}