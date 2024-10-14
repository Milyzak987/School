#include <iostream>
#include <set>
using namespace std;

const int MAX = 1e5 + 7;
const long long P1 = 15671;
const long long MOD1 = 1e9 + 7;
const long long P2 = 45377;
const long long MOD2 = 1000012309;
long long pow1[MAX];
long long pow2[MAX];

string in;
int n;

set<pair<long long, long long>> frag;

pair<long long, long long> makeHash(string& s) {
	long long hash1 = 0, hash2 = 0;
	for (int i = 0; i < s.length(); i++) {
		hash1 = (hash1 * P1 + s[i]) % MOD1;
		hash2 = (hash2 * P2 + s[i]) % MOD2;
	}
	return make_pair(hash1, hash2);
} 

void solve() {
	int z;
	cin >> z;
	if (z <= 0) return;
	
	string s;
	cin >> s;
	int m = s.length();
	if (m > n) return;
	
	frag.clear();
	
	long long hash1 = 0, hash2 = 0;
	for (int i = 0; i < m; i++) {
		hash1 = (hash1 * P1 + in[i]) % MOD1;
		hash2 = (hash2 * P2 + in[i]) % MOD2;
	}
	frag.insert(make_pair(hash1, hash2));
	
	for (int i = m; i < n; i++) {
		hash1 = (hash1 - (in[i - m] * pow1[m - 1]) % MOD1 + MOD1) % MOD1;
		hash1 = (hash1 * P1 + in[i]) % MOD1;
		
		hash2 = (hash2 - (in[i - m] * pow2[m - 1]) % MOD2 + MOD2) % MOD2;
		hash2 = (hash2 * P2 + in[i]) % MOD2;
		
		frag.insert(make_pair(hash1, hash2));
	}
	
	if (frag.find(makeHash(s)) == frag.end()) {
		cout << "NIE\n";
	} else {
		cout << "OK\n";
	}
	z--;
	
	while (z--) {
		cin >> s;
		if (frag.find(makeHash(s)) == frag.end()) {
			cout << "NIE\n";
		} else {
			cout << "OK\n";
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	pow1[0] = 1;
	pow2[0] = 1;
	for (int i = 1; i <= MAX; i++) {
		pow1[i] = (pow1[i - 1] * P1) % MOD1;
		pow2[i] = (pow2[i - 1] * P2) % MOD2;
	}
	
	cin >> in;
	n = in.length();
	
	int k;
	cin >> k;
	
	while (k--) {
		solve();
	}

	return 0;
}