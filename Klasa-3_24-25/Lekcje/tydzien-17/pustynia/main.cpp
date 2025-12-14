#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int R = (1 << 17);
const int MAXM = 200 * 1000;
const int MAXVAL = 1000 * 1000 * 1000;

const int QUERY = 2 * R;
const int MAXN = 2 * R + MAXM + 1;

vector<pii> graph[MAXN];
vector<int> reverseGraph[MAXN];
vector<int> values(MAXN, -1);
vector<int> inDegree(MAXN);
queue<int> q;

void connect(int start, int end, int v) {
    start += R - 1;
    end += R + 1;
    while (start / 2 != end / 2) {
        if (start % 2 == 0) {
            graph[v].push_back({start + 1, 0});
            reverseGraph[start + 1].push_back(v);
        }
        if (end % 2 == 1) {
            graph[v].push_back({end - 1, 0});
            reverseGraph[end - 1].push_back(v);
        }
        start /= 2;
        end /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, m;
    cin >> n >> s >> m;

    for (int i = 1; i <= s; i++) {
        int a;
        cin >> a;
        cin >> values[R + a];
    }

    for (int i = R - 1; i >= 1; i--) {
        graph[i].push_back({2 * i, 0});
        reverseGraph[2 * i].push_back(i);
        graph[i].push_back({2 * i + 1, 0});
        reverseGraph[2 * i + 1].push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        int currentPos = l;

        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;

            if (currentPos <= x - 1) {
                connect(currentPos, x - 1, QUERY + i);
            }
            currentPos = x + 1;

            graph[R + x].push_back({QUERY + i, 1});
            reverseGraph[QUERY + i].push_back(R + x);
        }

        if (currentPos <= r) {
            connect(currentPos, r, QUERY + i);
        }
    }

    for (int i = 1; i < MAXN; i++) {
        inDegree[i] = (int)graph[i].size();
        if (inDegree[i] <= 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : reverseGraph[v]) {
            inDegree[u]--;
            if (inDegree[u] <= 0) {
                q.push(u);
            }
        }

        int maxVal = 1;
        for (pii p : graph[v]) {
            maxVal = max(maxVal, values[p.first] + p.second);
        }

        if (maxVal > MAXVAL) {
            cout << "NIE";
            return 0;
        }

        if (values[v] == -1) {
            values[v] = maxVal;
        } else if (maxVal > values[v]) {
            cout << "NIE";
            return 0;
        }
    }

    // Check for cycles
    for (int i = 1; i < MAXN; i++) {
        if (inDegree[i] != 0) {
            cout << "NIE\n";
            return 0;
        }
    }

    cout << "TAK\n";
    for (int i = R + 1; i <= R + n; i++) {
        cout << values[i] << " ";
    }

    return 0;
}