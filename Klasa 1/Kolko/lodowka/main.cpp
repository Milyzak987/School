#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // Define variables and initialize them
    int n, x = 0;
    vector<int> a, b;
    unordered_map<int, int> counts;

    // Read input
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        counts[a[i]]++;
        counts[b[i]]++;
    }

    // Compute result
    for (const auto& [value, count] : counts) {
        x = max(x, count);
    }

    // Print result
    cout << x;

    return 0;
}