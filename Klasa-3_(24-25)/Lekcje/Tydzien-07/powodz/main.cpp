#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

const int INF = 2e9;
const int MAXN = 1007;
int in[MAXN][MAXN];
int rep[MAXN * MAXN];
bool pump[MAXN * MAXN];
vector<Pair> height[MAXN];
int deltaX[] = {1, 0, -1, 0};
int deltaY[] = {0, 1, 0, -1};

int idx(int x, int y) { return (y - 1) * MAXN + x; }

int Find(int x) {
    if (rep[x] == x)
        return x;
    return (rep[x] = Find(rep[x]));
}

bool Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b)
        return false;
    rep[a] = b;
    pump[b] = (pump[b] || pump[a]);
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= MAXN * MAXN; i++) {
        rep[i] = i;
    }
    for (int x = 1; x <= n; x++) {
        in[x][0] = INF;
        in[x][m + 1] = INF;
    }
    for (int y = 1; y <= m; y++) {
        in[0][y] = INF;
        in[n + 1][y] = INF;
    }

    for (int y = 1; y <= m; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> in[x][y];
            height[abs(in[x][y])].push_back({x, y});
        }
    }

    int res = 0;
    for (int h = 1; h <= MAXN; h++) {
        for (Pair p : height[h]) {
            int curr = idx(p.first, p.second);
            for (int i = 0; i < 4; i++) {
                int newX = p.first + deltaX[i];
                int newY = p.second + deltaY[i];
                if (abs(in[newX][newY]) <= abs(in[p.first][p.second])) {
                    Union(curr, idx(newX, newY));
                }
            }
        }
        for (Pair p : height[h]) {
            int g = Find(idx(p.first, p.second));
            if (pump[g])
                continue;
            if (in[p.first][p.second] < 0)
                continue;
            pump[g] = true;
            res++;
        }
    }
    cout << res;

    return 0;
}