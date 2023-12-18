#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> arr(1000007);

bool czyKolejneLiczbyWKolejnosci(int s, int n, int k) {
    unordered_set<int> set;
    
    for (int i = s; i < n; i++) {
        set.insert(arr[i]);
    }
    
    for (int i = s; i <= n - k; i++) {
        bool found = true;
        for (int j = s; j < k; j++) {
            if (set.find(arr[i + j]) == set.end()) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = a;
    }

    pair<int, int> wyn1;
    int wyn = 1000000000, head = 0, tail = 1, curr = 0;
    while (head < n) {
        head++;
        if(czyKolejneLiczbyWKolejnosci(tail, head, k)){
            wyn = min(wyn, head - tail + 1);
            wyn1 = {tail, head};
            while(czyKolejneLiczbyWKolejnosci(tail, head, k)){
                tail++;
            }
            tail--;
        }
    }
    cout << wyn << "\n" << wyn1.first << " " << wyn1.second;
}