#include <iostream>
using namespace std;

struct V {
    long double x, y;
};
const int MAXN = 1e6 + 7;
V polygon[MAXN], point;

bool edge(V point, V p1, V p2) {
    return ((point.x >= min(p1.x, p2.x)) && (point.x <= max(p1.x, p2.x)) &&
            (point.y >= min(p1.y, p2.y) && point.y <= max(p1.y, p2.y)) &&
            ((point.x - p1.x) * (p2.y - p1.y) == (p2.x - p1.x) * (point.y - p1.y)));
}

string inside(V& point, V* polygon, int n) {
    bool in = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (edge(point, polygon[i], polygon[j])) return "KRAWEDZ";

        bool b1 = (polygon[i].y > point.y) != (polygon[j].y > point.y);
        long double o1 = (polygon[j].x - polygon[i].x);
        long double o2 = (point.y - polygon[i].y);
        long double o3 = (polygon[j].y - polygon[i].y);
        long double o4 = polygon[i].x;
        if (b1 && point.x < o1 * o2 / o3 + o4) {
            in = !in;
        }
    }
    return in ? "WEWNATRZ" : "NA ZEWNATRZ";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%Lf %Lf", &polygon[i].x, &polygon[i].y);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%Lf %Lf", &point.x, &point.y);
        printf("%s\n", inside(point, polygon, n).c_str());
    }
}