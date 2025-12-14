#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MAXN = 1e5 + 7;
ll added[MAXN];
ll stealA[MAXN];
ll stealB[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, A, B;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> added[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> stealA[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> stealB[i];
    }
    cin >> A >> B;

    for(ll i = 0; i < n; i++){
        A += added[i];
        B += added[i];

        if(A - stealA[i] > B - stealB[i]){
            B = min(B, stealB[i]);
        } else {
            A = min(A, stealA[i]);
        }
    }

    cout << A + B;
}