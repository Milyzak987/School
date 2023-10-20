#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare_add(const vector<long long>& v1, const vector<long long>& v2) {
    return v1[0] < v2[0];
}

bool compare_take(const vector<long long>& v1, const vector<long long>& v2) {
    return v1[1] > v2[1];
}

int main() {
    long long n, hp;
    cin >> n >> hp;

    vector<vector<long long>> take;
    vector<vector<long long>> add;

    for (long long i = 0; i < n; i++) {
        long long dmg, pot;
        cin >> dmg >> pot;
        if (pot - dmg < 0) {
            take.push_back({dmg, pot, i});
        } else {
            add.push_back({dmg, pot, i});
        }
    }
    sort(take.begin(), take.end(), compare_take);
    sort(add.begin(), add.end(), compare_add);

    for (long long i = 0; i < add.size(); i++) {
        hp -= add[i][0];
        if (hp <= 0) {
            cout << "NIE";
            return 0;
        }
        hp += add[i][1];
    }
    for (long long i = 0; i < take.size(); i++) {
        hp -= take[i][0];
        if (hp <= 0) {
            cout << "NIE";
            return 0;
        }
        hp += take[i][1];
    }
    cout << "TAK" << endl;
    for (long long i = 0; i < add.size(); i++) {
        cout << add[i][2] + 1 << " ";
    }
    for (long long i = 0; i < take.size(); i++) {
        cout << take[i][2] + 1 << " ";
    }
    return 0;
}
