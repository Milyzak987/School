#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 7;
const int INF = 2e9;
int A[MAXN];
int B[MAXN];
int schematy[MAXN];
int dp[MAXN];

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
                cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
                cin >> B[i];
        }

        for (int i = 1; i <= n; i++) {
                schematy[A[i]] = min(schematy[A[i]], A[i] - B[i]);
        }
        for (int i = 1; i <= MAXN; i++) {
                schematy[i] = min(schematy[i], schematy[i - 1]);
        }

        for (int i = 1; i <= MAXN; i++) {
                if (schematy[i] != INT_MAX) {
                        dp[i] = dp[max(0, i - schematy[i])] + 2;
                }
        }

        ll wynik = 0;
        for (int i = 1; i <= m; i++) {
                int masa;
                cin >> masa;

                while (masa > MAX) {
                        int ile = (masa - MAX - 1) / schematy[MAX] + 1;
                        masa -= ile * schematy[MAX];
                        wynik += 2 * ile;
                }
                wynik += dp[masa];
        }
        cout << wynik;

        return 0;
}

