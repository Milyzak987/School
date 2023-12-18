#include <iostream>
#include <unordered_set>
using namespace std;

bool czyKolejneLiczbyWKolejnosci(int arr[], int n, int k) {
    unordered_set<int> set;
    
    for (int i = 0; i < n; i++) {
        set.insert(arr[i]);
    }
    
    for (int i = 0; i <= n - k; i++) {
        bool found = true;
        for (int j = 0; j < k; j++) {
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
    int arr[] = {2, 3, 4, 5};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    if (czyKolejneLiczbyWKolejnosci(arr, n, k)) {
        cout << "Znaleziono " << k << " kolejne liczby." << endl;
    } else {
        cout << "Nie znaleziono " << k << " kolejnych liczb." << endl;
    }
    
    return 0;
}
