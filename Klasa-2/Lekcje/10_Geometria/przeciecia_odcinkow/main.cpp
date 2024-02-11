#include <iostream>
using namespace std;

bool onSegment(pair<long long, long long> p, pair<long long, long long> q, pair<long long, long long> r) {
    if (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first) &&
        q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second))
        return true;
    return false;
}

long long orientation(pair<long long, long long> p, pair<long long, long long> q, pair<long long, long long> r) {
    long long val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool solve() {
    pair<long long, long long> A, B, C, D;
    cin >> A.first >> A.second >> B.first >> B.second;
    cin >> C.first >> C.second >> D.first >> D.second;


    long long o1 = orientation(A, B, C);
    long long o2 = orientation(A, B, D);
    long long o3 = orientation(C, D, A);
    long long o4 = orientation(C, D, B);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(A, C, B)) return true;
    if (o2 == 0 && onSegment(A, D, B)) return true;
    if (o3 == 0 && onSegment(C, A, D)) return true;
    if (o4 == 0 && onSegment(C, B, D)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    while(n--){
        if (solve()) {
            cout << "TAK" << '\n';
        } else {
            cout << "NIE" << '\n';
        }
    }
    return 0;
}