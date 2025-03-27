// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> Pair;

// const int MAXN = 2e5 + 7;
// int arr[MAXN];
// priority_queue<Pair, vector<Pair>, greater<Pair>> q;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, k;
//     cin >> n >> k;

//     for (int i = 1; i <= n; i++) {
//         cin >> arr[i];
//     }

//     sort(arr + 1, arr + 1 + n);

//     Pair curr = {arr[1], 1};
//     q.push({arr[1], 1});

//     for (int i = 1; i <= k; i++) {
//         curr = q.top();
//         q.pop();

//         if (curr.second + 1 > n) continue;

//         q.push({curr.first + arr[curr.second + 1], curr.second + 1});
//         q.push({curr.first - arr[curr.second] + arr[curr.second + 1], curr.second + 1});
//     }

//     cout << curr.first;

//     return 0;
// }

#include <iostream>
using namespace std;

int main(){
    cout << "Zrobione";
}