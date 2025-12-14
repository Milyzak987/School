#include <iostream>
using namespace std;

const int MAX = 16e6 + 7;
int lps[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string pat, txt;
	cin >> pat >> txt;
	
	string s = "-" + pat + "-" + txt;
	
	lps[0] = -1;
	lps[1] = 0;
	for (int i = 2; i < s.length(); i++) {
		int res = lps[i - 1];
		while (res >= 0 && s[i] != s[res + 1]) {
			res = lps[res];
		}
		lps[i] = res + 1;
	}
	
	for (int i = n + 2; i < s.length(); i++) {
		if (lps[i] == n) {
			cout << i - 2 * n << "\n";
		}
	}
	
	return 0;
}