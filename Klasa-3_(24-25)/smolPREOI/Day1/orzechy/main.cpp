#include <iostream>
using namespace std;

const int MAXN = 1e5 + 7;
int added[MAXN];
int stealA[MAXN];
int stealB[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, A, B;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> added[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> stealA[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> stealB[i];
    }
    cin >> A >> B;

    for(int i = 0; i < n; i++){
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