#include <bits/stdc++.h>
using namespace std;

int randrange(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    for (int j = 1; j <= 10000; j++) {
        srand(time(NULL) * j);
        string name = "testy/test" + to_string(j) + ".in";

        ofstream file(name);

        int n = randrange(3, 10);
        file << n << "\n";

        vector<int> nums(n);
        int x = randrange(1, n - 1);
        if (x == n / 2) x++;
        if (x > n / 2) {
            fill(nums.begin(), nums.begin() + x, 0);
            fill(nums.begin() + x + 1, nums.end(), 1);
        } else {
            fill(nums.begin(), nums.begin() + x, 1);
            fill(nums.begin() + x + 1, nums.end(), 0);
        }

        shuffle(nums.begin(), nums.end(), default_random_engine(time(NULL) * j));

        for (int i = 0; i < n; i++) {
            file << nums[i] << " ";
            ;
        }
        file << "\n";
        for (int i = 0; i < n; i++) {
            file << randrange(1, 10) << " ";
        }
        file.close();
    }
}