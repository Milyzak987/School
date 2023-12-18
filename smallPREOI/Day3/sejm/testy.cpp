#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

int randrange(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    for (int j = 1; j <= 100; j++) {
        srand(time(NULL) * j);
        string name = "testy/test" + to_string(j) + ".in";

        ofstream file(name);

        int n = randrange(3, 20);

        file << n << "\n";

        int zeros = 0, ones = 0;
        for (int i = 1; i < n; i++) {
            int num = randrange(0, 1);
            if(ones > zeros) num = 0;
            zeros += (num == 0) ? 1 : 0;
            ones += (num == 1) ? 1 : 0;
            file << num << " ";
        }
        if(ones + 1 >= zeros) file << 0;
        else file << 1;
        file << "\n";
        for (int i = 0; i < n; i++) {
            file << randrange(1, 1000) << " ";
        }
        file.close();
    }
}