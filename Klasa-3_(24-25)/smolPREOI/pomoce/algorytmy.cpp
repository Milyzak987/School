#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
int arr[MAXN];
int visited[MAXN];
int dist[MAXN];
int degree[MAXN];
int jump[MAXN][20];
int depth[MAXN];
vector<int> graph1[MAXN];
vector<pll> graph2[MAXN];

int binarySearch(int x, int left, int right) {
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

int gasienica(int n, int x) {
    int wyn = INF, glowa = 0, ogon = 1, akt_sum = 0;
    while (glowa < n) {
        glowa++;
        akt_sum += arr[glowa];
        if (akt_sum < x) {
            continue;
        }
        if (akt_sum == x) {
            wyn = min(wyn, glowa - ogon + 1);
        }
        while (ogon < glowa && akt_sum >= x) {
            akt_sum -= arr[ogon];
            ogon++;
            if (akt_sum == x) {
                wyn = min(wyn, glowa - ogon + 1);
            }
        }
    }
    return wyn;
}

int DFS(int v) {
    visited[v] = true;
    for (int u : graph1[v]) {
        if (!visited[u]) DFS(u);
    }
}

// fill dist with -1
void BFS(int x) {
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : graph1[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

// fill dist with INF
void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        for (auto p : graph2[v]) {
            int u = p.first;
            int w = p.second;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}

void zeroOneBFS(int s) {
    deque<int> dq;
    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty()) {
        int v = dq.front();
        dq.pop_front();

        for (auto p : graph2[v]) {
            int u = p.first;
            int w = p.second;
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;

                if (w == 0) {
                    dq.push_front(u);
                } else {
                    dq.push_back(u);
                }
            }
        }
    }
}

void DFS_jump(int v) {
    visited[v] = 1;
    for (int u : graph1[v]) {
        if (!visited[u]) {
            jump[u][0] = v;
            depth[u] = depth[v] + 1;
            DFS_jump(u);
        }
    }
}

// L = log(n)
void jumpPointers(int L, int n) {
    for (int i = 0; i < L; i++) {
        for (int v = 1; v < n; v++) {
            jump[v][i] = jump[jump[v][i - 1]][i - 1];
        }
    }
}

int LCA(int u, int v, int L) {
    if (depth[u] > depth[v]) swap(v, u);

    for (int i = L; i >= 0; i--) {
        if (depth[jump[v][i]] >= depth[u]) {
            v = jump[v][i];
        }
    }

    if(v == u) return v;

    for (int i = L; i >= 0; i--) {
        if (jump[u][i] != jump[v][i]) {
            u = jump[u][i];
            v = jump[v][i];
        }
    }

    return jump[v][0];
}

int szybkiePotegowanie(long long a, long long b) {
    long long wynik = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            wynik = (wynik * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;
    cout << x;
}