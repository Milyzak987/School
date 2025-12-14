#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int MAXN = 2e5 + 7;
vector<int> groups[MAXN];
vector<Pair> queries[MAXN];
Pair edges[MAXN];
int parent[MAXN];
int results[MAXN];

int findd(int x) {
    if (x == parent[x]) return x;
    return (parent[x] = findd(parent[x]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        groups[i].push_back(i);
    }
    
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        queries[a].push_back({b, i});
        queries[b].push_back({a, i});
        results[i] = (a == b ? 0 : -1);
    }
    
    for (int i = 1; i <= m; i++) {
        int a = findd(edges[i].first);
        int b = findd(edges[i].second);
        if (a == b) continue;
        
        if (groups[b].size() > groups[a].size()) swap(a, b);
        parent[b] = a;
        for (int x : groups[b]) {
            groups[a].push_back(x);
            
            for (Pair p : queries[x]) {
                if (results[p.second] != -1) continue;
                if (findd(x) != findd(p.first)) continue;
                results[p.second] = i;
            }
        }
    }
    
    for (int i = 1; i <= q; i++) {
        if (results[i] == -1) {
            cout << "+oo\n";
        } else {
            cout << results[i] << "\n";
        }
    }

    return 0;
}
