#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int MAXN = 1007;
vector<int> arr(MAXN);
deque<pair<int, int>> ans;

void applyXOR(int i, int j) {
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
    ans.push_back({i, j});
}

void bubbleToPosition(int idx, int target) {
    while (idx > target) {
        applyXOR(idx - 1, idx);
        idx--;
    }
}

void merge(int left, int mid, int right) {
    vector<int> merged;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            merged.push_back(arr[i++]);
        } else {
            merged.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        merged.push_back(arr[i++]);
    }

    while (j <= right) {
        merged.push_back(arr[j++]);
    }

    for (int k = 0; k < merged.size(); k++) {
        if (arr[left + k] != merged[k]) {
            bubbleToPosition(left + k, left + k - 1);
            arr[left + k] = merged[k];
        }
    }
}

void mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = n; i > 0; i--) {
        cout << i << " ";
    }

    return 0;
}