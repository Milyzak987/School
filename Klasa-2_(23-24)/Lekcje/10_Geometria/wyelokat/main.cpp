#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 7;

vector<pair<long long, long long>> points(MAXN);

long long area(int n) {
    long long area = 0;
    for (int i = 0; i < n; i++) {
        area += (points[i + 1].first - points[i].first) * (points[i + 1].second + points[i].second);
    }
    return abs(area);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &points[i].first, &points[i].second);
    }
    points[n].first = points[0].first;
    points[n].second = points[0].second;

    long long result = area(n);

    if (result % 2 == 0)
        printf("%lld", result / 2);
    else {
        printf("%lld.5", (result - 1) / 2);
    }
    return 0;
}