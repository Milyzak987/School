#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 7;

ll arr[MAXN];
int res[MAXN];
int p[MAXN];
int pom[MAXN];
int n;

void com(int (&f)[MAXN], int (&g)[MAXN]) {
    for (int i = 1; i <= n; i++) {
        pom[i] = f[g[i]];
    }
    for (int i = 1; i <= n; i++) {
    	f[i] = pom[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	ll m;
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int left = 1, right = min(n, k + 1);
    for (int i = 1; i <= n; i++) {
        while (right + 1 <= n && abs(arr[i] - arr[left]) > abs(arr[i] - arr[right + 1])) {
            right++;
            left++;
        }
        
		int cl;
		if (i == left) cl = right;
		else if (i == right) cl = left;
		else if (abs(arr[i] - arr[left]) >= abs(arr[i] - arr[right])) cl = left;
		else cl = right;
        
        p[i] = cl;
        res[i] = cl;
    }
    
    m--;
    while (m) {
        if (m & 1) {
            com(res, p);
        }
        com(p, p);
        m /= 2;
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}