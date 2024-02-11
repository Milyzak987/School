#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> target(n);
    for (int i = 0; i < n; ++i) {
        cin >> target[i];
    }

    vector<int> moves;
    for (int i = 0; i < n; ++i) {
        int idx = -1;
        if (arr[0] == target[i]) {
            idx = 0;
        } else if (arr[1] == target[i]) {
            idx = 1;
        }

        while (idx > 1) {
            moves.push_back(2);
            swap(arr[idx], arr[idx - 1]);
            idx--;
        }

        moves.push_back(idx + 1);
        arr.erase(arr.begin() + idx);
        arr.push_back(target[i]);
    }

    for (int move : moves) {
        cout << move;
    }

    return 0;
}