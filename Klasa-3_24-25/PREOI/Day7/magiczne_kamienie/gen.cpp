#include <bits/stdc++.h>
using namespace std;

const int TESTS = 10;
const int N = 1000;
const string DIRECTORY = "in/";

void generate_test(int test_number) {
    string filename = DIRECTORY + "test" + to_string(test_number) + ".txt";
    ofstream out(filename);
    
    if (!out) {
        cerr << "Nie można otworzyć pliku: " << filename << '\n';
        return;
    }

    out << N << '\n';

    string s(N, 'T');
    for (int i = 1; i < N; i++) {
        s[i] = (rand() % 2 == 0 ? 'T' : 'R');
    }

    out << s << '\n';
    out.close();
}

int main() {
    srand(time(0));

    system(("mkdir -p " + DIRECTORY).c_str());

    for (int i = 1; i <= TESTS; i++) {
        generate_test(i);
    }

    cout << "Wygenerowano " << TESTS << " testów w folderze '" << DIRECTORY << "'\n";
    return 0;
}