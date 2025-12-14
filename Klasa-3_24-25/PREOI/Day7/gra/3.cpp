#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Opponent {
    vector<int> u;
    vector<int> z;
    int sum_z;
    int index;
};

struct CompareSumZ {
    bool operator()(const Opponent &a, const Opponent &b) { return a.sum_z < b.sum_z; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Opponent> opponents(n);
    for (int i = 0; i < n; ++i) {
        opponents[i].u.resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> opponents[i].u[j];
        }
        opponents[i].index = i;
    }
    for (int i = 0; i < n; ++i) {
        opponents[i].z.resize(k);
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            cin >> opponents[i].z[j];
            sum += opponents[i].z[j];
        }
        opponents[i].sum_z = sum;
    }

    vector<int> current_sum(k, 0);
    vector<bool> defeated(n, false);
    priority_queue<Opponent, vector<Opponent>, CompareSumZ> eligible;

    for (int i = 0; i < n; ++i) {
        bool can_defeat = true;
        for (int j = 0; j < k; ++j) {
            if (opponents[i].u[j] > current_sum[j]) {
                can_defeat = false;
                break;
            }
        }
        if (can_defeat) {
            eligible.push(opponents[i]);
            defeated[i] = true;
        }
    }

    int count = 0;

    while (!eligible.empty()) {
        Opponent current = eligible.top();
        eligible.pop();
        count++;

        for (int j = 0; j < k; ++j) {
            current_sum[j] += current.z[j];
        }

        for (int i = 0; i < n; ++i) {
            if (defeated[i])
                continue;
            bool can_defeat = true;
            for (int j = 0; j < k; ++j) {
                if (opponents[i].u[j] > current_sum[j]) {
                    can_defeat = false;
                    break;
                }
            }
            if (can_defeat) {
                eligible.push(opponents[i]);
                defeated[i] = true;
            }
        }
    }

    cout << count;

    return 0;
}