#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> Pair;

const int MAXN = 2007;
ull c[MAXN][MAXN];
vector<ull> row(MAXN);
vector<ull> col(MAXN);
vector<ull> rowWeights(MAXN);
vector<ull> colWeights(MAXN);

void calWeights(ull limit, vector<ull>& values, vector<ull>& weights) {
    for (ull x = 0; x <= limit; x++) {
        ull curr = 0;
        
        ull odle = 2;
        for (ull i = x; i >= 1; i--) {
            curr += odle * odle * values[i];
            odle += 4;
        }

        odle = 2;
        for (ull i = x + 1; i <= limit; i++) {
            curr += odle * odle * values[i];
            odle += 4;
        }

        weights[x] = curr;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ull n, m;
	cin >> n >> m;
	
	for (ull y = 1; y <= n; y++) {
		for (ull x = 1; x <= m; x++) {
			cin >> c[x][y];
			row[y] += c[x][y];
			col[x] += c[x][y];
		}
	}
	
    calWeights(m, col, colWeights);
    calWeights(n, row, rowWeights);
	
	ull res = colWeights[0] + rowWeights[0];
    Pair best = {0, 0};
	for (ull i = 0; i <= n; i++) {
		for (ull j = 0; j <= m; j++) {
			ull curr = colWeights[j] + rowWeights[i];
			if (curr < res) {
				res = curr;
                best = {i, j};
			}
		}
	}
	cout << res << "\n" << best.first << " " << best.second;
	
	return 0;
}