#include <iostream>
#include <vector>

#include "stu2lib.h"
using namespace std;

constexpr int INF = 2e9 + 7, base = 1 << 18;
int tree[2 * base];
int n;

int query(int a, int b) {
    if (min(a, b) < 0) return INF;

    a += base;
    b += base;
    int res = min(tree[a], tree[b]);
    while (a / 2 != b / 2) {
        if (a % 2 == 0) res = min(res, tree[a + 1]);
        if (b % 2 == 1) res = min(res, tree[b - 1]);
        a /= 2;
        b /= 2;
    }

    return res;
}

void inicjuj(vector<int> arr) {
    n = arr.size();

    for (int i = 1; i < 2 * base; i++) tree[i] = INF;
    for (int i = 0; i < n; i++) tree[base + i] = arr[i];
    for (int i = base - 1; i >= 1; i--) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

int odpowiedz(int a, int b) {
    a--;
    b--;
    int t = min(query(0, a - 1), query(b + 1, n));
    return min(t, n);
}

void changeTree(int x) {
    while (x > 1) {
        x /= 2;
        tree[x] = min(tree[2 * x], tree[2 * x + 1]);
    }
}

void zamien(int a, int b) {
    a += base - 1;
    b += base - 1;
    swap(tree[a], tree[b]);
    changeTree(a);
    changeTree(b);
}