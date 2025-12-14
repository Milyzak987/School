// #include <iostream>
// #include <vector>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> Pair;

// struct qq {
//     char t;
//     int x, y;
// };

// const int MAXN = 2e5 + 7;
// int rep[MAXN];
// int res[MAXN];
// bool activated[MAXN];
// qq que[MAXN];
// vector<int> group[MAXN];
// vector<Pair> op;

// int Find(int x) {
//     if (rep[x] == x)
//         return x;
//     return (rep[x] = Find(rep[x]));
// }

// void Union(int a, int b, int indeks) {
//     a = Find(a);
//     b = Find(b);
//     if (a == b)
//         return;

//     if (activated[a] && activated[b]) {
//         rep[a] = b;
//         return;
//     }

//     if (!activated[a] && !activated[b]) {
//         if (group[a].size() > group[b].size())
//             swap(a, b);
//         for (int x : group[a]) {
//             group[b].push_back(x);
//         }
//         rep[a] = b;
//         return;
//     }

//     if (activated[a])
//         swap(a, b);
//     rep[a] = b;
//     for (int x : group[a]) {
//         res[x] = indeks;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, q;
//     cin >> n >> q;

//     for (int i = 1; i <= n; i++) {
//         activated[i] = true;
//         rep[i] = i;
//     }

//     op.push_back({-1, false});
//     for (int i = 1; i <= q; i++) {
//         cin >> que[i].t >> que[i].x;
//         if (que[i].t == 'A') {
//             cin >> que[i].y;
//             op.push_back({i, true});
//         } else if (que[i].t == 'R') {
//             op[que[i].x].second = false;
//             que[i].y = que[op[que[i].x].first].y;
//             que[i].x = que[op[que[i].x].first].x;
//         } else {
//             activated[que[i].x] = false;
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         if (!activated[i]) {
//             group[i].push_back(i);
//         } else {
//             res[i] = q;
//         }
//     }

//     for (Pair p : op) {
//         if (p.second) {
//             Union(que[p.first].x, que[p.first].y, q);
//         }
//     }

//     for (int i = q; i >= 1; i--) {
//         if (que[i].t == 'A')
//             continue;
//         if (que[i].t == 'R') {
//             Union(que[i].x, que[i].y, i - 1);
//         } else {
//             int x = Find(que[i].x);
//             if (activated[x])
//                 continue;
//             activated[x] = true;
//             for (int y : group[x]) {
//                 res[y] = i - 1;
//             }
//             group[x].clear();
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         cout << res[i] << "\n";
//     }

//     return 0;
// }

#include <iostream>
using namespace std;

int main(){
    cout << "Zrobione";
}