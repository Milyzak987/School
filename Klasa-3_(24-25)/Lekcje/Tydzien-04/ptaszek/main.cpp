#include <iostream>
#include <deque>
using namespace std;

struct p {
	int z, h, i;
};

bool comp(const p& a, const p& b) {
	if (a.z < b.z) return true;
	if (a.z > b.z) return false;
    if (a.h > b.h) return true;
	return false;
}

const int MAXN = 1e6 + 7;
int trees[MAXN];
deque<p> dq;
 
int solve(int n, int k) {
	while (!dq.empty()) dq.pop_back();
	
	int cur = 0;
	dq.push_back({0, trees[1], 1});
	
	for (int i = 2; i <= n; i++) {
		if (!dq.empty() && dq.front().i == i - k - 1) dq.pop_front();
		
		p e = dq.front();
		
		cur = e.z;
		if (e.h <= trees[i]) cur++;
		
		p neww = {cur, trees[i], i};
		while (!dq.empty() && comp(neww, dq.back())) dq.pop_back();
		dq.push_back(neww);
	}
	
	return cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> trees[i];
	}
	
	int q;
	cin >> q;
	
	while (q--) {
		int k;
		cin >> k;
		cout << solve(n, k) << '\n';
	}

	return 0;
}