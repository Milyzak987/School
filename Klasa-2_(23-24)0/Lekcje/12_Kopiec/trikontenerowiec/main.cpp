#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 1e6 + 7;
vector<pair<int, int>> v(MAXN);

class heap {
   private:
    int* T;
    int n;

   public:
    heap(int max_n);
    bool empty();
    int top();
    void push(int v);
    void pop();
};

heap::heap(int max_n) {
    T = new int[max_n];
    n = 0;
}

bool heap::empty() {
    return !n;
}

int heap::top() {
    return T[0];
}

void heap::push(int v) {
    int i, j;

    i = n++;
    j = (i - 1) / 2;

    while (i > 0 && T[j] < v) {
        T[i] = T[j];
        i = j;
        j = (i - 1) / 2;
    }

    T[i] = v;
}

void heap::pop() {
    int i, j, v, p;

    if (n--) {
        p = T[n];

        i = 0;
        j = 1;

        while (j < n) {
            if (j + 1 < n && T[j + 1] > T[j]) j++;
            if (p >= T[j]) break;
            T[i] = T[j];
            i = j;
            j = 2 * j + 1;
        }

        T[i] = p;
    }
}

bool comp(const pair<int, int> a, const pair<int, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    heap h(MAXN);
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        int w, h;
        scanf("%d%d", &w, &h);
        v[i] = {w, h};
    }
    sort(v.begin(), v.begin() + n, comp);
    int j = 0, res = 0;
    for (int i = 1; i <= m; i++) {
        if (v[j].second > i) {
            if (!h.empty()) {
                res += h.top();
                h.pop();
            }
            continue;
        }
        while (v[j].second <= i && j < n) {
            h.push(v[j].first);
            ++j;
        }
        if (!h.empty()) {
            res += h.top();
            h.pop();
        }
    }
    printf("%d", res);
}