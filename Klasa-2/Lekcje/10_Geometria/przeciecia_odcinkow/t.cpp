#include <iostream>
using namespace std;

// Structure to represent a point
struct Point {
    int x, y;
};

// Function to find orientation of triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Function to check if two line segments intersect
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && p2.x >= min(p1.x, q1.x) && p2.x <= max(p1.x, q1.x) &&
        p2.y >= min(p1.y, q1.y) && p2.y <= max(p1.y, q1.y))
        return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && p2.x >= min(p1.x, q1.x) && p2.x <= max(p1.x, q1.x) &&
        p2.y >= min(p1.y, q1.y) && p2.y <= max(p1.y, q1.y))
        return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && p1.x >= min(p2.x, q2.x) && p1.x <= max(p2.x, q2.x) &&
        p1.y >= min(p2.y, q2.y) && p1.y <= max(p2.y, q2.y))
        return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && p1.x >= min(p2.x, q2.x) && p1.x <= max(p2.x, q2.x) &&
        p1.y >= min(p2.y, q2.y) && p1.y <= max(p2.y, q2.y))
        return true;

    return false; // Doesn't fall in any of the above cases
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        if (doIntersect(A, B, C, D)) {
            cout << "TAK" << '\n';
        } else {
            cout << "NIE" << '\n';
        }
    }
    return 0;
}
