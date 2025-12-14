// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// const int INF = (1 << 30);
// const int MAX = 2e5 + 7;
// int przed[MAXN];
// int wyst[MAXN];
// int graf[MAXN];
// int graf_pom[MAXN];
// int pom[MAXN];
// int koniec[MAXN];

// void zloz(int m, int (&f)[MAXN], int (&g)[MAXN]) {
//     for (int i = 1; i <= m; i++) {
//         pom[i] = f[g[i]];
//     }
//     for (int i = 1; i <= m; i++) {
//     	f[i] = pom[i];
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	int n, m, q;
// 	cin >> n >> m >> q;
	
// 	int pop = -1, pierwsze = -1;
// 	for (int i = 1; i <= n; i++) {
// 		int a;
// 		cin >> a;
// 		if (pierwsze == -1) pierwsze = a;
// 		przed[a] = pop;
// 		pop = a;
// 	}
// 	przed[pierwsze] = pop;
	
// 	for (int i = 1; i <= m; i++) {
// 		int a;
// 		cin >> a;
// 		graf[i] = i;
// 		graf_pom[i] = wyst[przed[a]];
// 		wyst[a] = i;
// 	}
	
// 	n -= 1;
// 	while (n) {
// 		if (n & 1) {
// 			zloz(m, graf, graf_pom);
// 		}
// 		zloz(m, graf_pom, graf_pom);
// 		n /= 2;
// 	}
	
// 	for (int i = 1; i <= m; i++) {
// 		koniec[i] = INF;
// 	}
// 	for (int i = 1; i <= m; i++) {
// 		koniec[graf[i]] = min(koniec[graf[i]], i);
// 	}
// 	for (int i = m - 1; i >= 1; i--) {
// 		koniec[i] = min(koniec[i], koniec[i + 1]);
// 	}
	
// 	while (q--) {
// 		int a, b;
// 		cin >> a >> b;
// 		cout << (koniec[a] <= b ? 1 : 0);
// 	}
	
// 	return 0;
// }

#include <iostream>
using namespace std;

int main(){
    cout << "Zrobione";
}