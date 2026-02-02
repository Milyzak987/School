#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2;
const long long MAXV = 1e12;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist1(1, MAXN);
    uniform_int_distribution<long long> dist2(0, MAXV);
    uniform_int_distribution<int> dist3(1, 2);

    for (int i = 1; i <= 10; i++) {
        string filename = "rand10/test" + to_string(i) + ".in";
        ofstream out(filename);
        int t = 2;
        int n = dist1(gen);
        out << t << " " << n << "\n";

        set<long long> s;
        while(s.size() < n){
            long long a = dist2(gen);
            s.insert(a);
        }
        for(auto x : s){
            out << x << " ";
        }
    }

    return 0;
}