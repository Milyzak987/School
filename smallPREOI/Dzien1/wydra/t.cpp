#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct V {
    vector<int> al, ral;
    int s = -1, v = 0, i = 0, b = -1;
    bool vis;
};

V v[200007];
vector<V> sv;
vector<pair<int, int>> po;
stack<int> st;

int cpo = 1;

void dfs(int x) {
    v[x].vis = true;

    for (int y : v[x].al) {
        if (!v[y].vis) dfs(y);
    }
    po.push_back({-cpo, x});
    cpo++;
}

int csi = 0;

void csv(int x) {
    v[x].s = csi;
    sv[csi].v++;

    for (int y : v[x].ral) {
        if (v[y].s == -1) {
            csv(y);
        } else if (v[y].s != csi) {
            sv[v[y].s].al.push_back(csi);
            sv[csi].i++;
        }
    }
}

void cs(int x) {
    sv[x].b = sv[x].v;
    if (sv[x].b == 1) sv[x].b = 0;

    int bc = 0;
    for (int y : sv[x].al) {
        if (sv[y].b == -1) {
            cs(y);
        }
        bc = max(bc, sv[y].b + 1);
    }
    sv[x].b += bc;
}

int ri() {
    bool m = false;
    int r = 0;
    char c;
    c = getchar();
    while (true) {
        if (c == '-') break;
        if (c >= '0' && c <= '9') break;
        c = getchar();
    }
    if (c == '-')
        m = true;
    else
        r = c - '0';
    while (true) {
        c = getchar();
        if (c < '0' || c > '9') break;
        r = r * 10 + (c - '0');
    }
    if (m)
        return -r;
    else
        return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = ri(), m = ri();

    for (int i = 1; i <= m; i++) {
        int a = ri(), b = ri();
        v[a].al.push_back(b);
        v[b].ral.push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].vis) continue;
        dfs(i);
    }

    sort(po.begin(), po.end());

    for (auto x : po) {
        int c = x.second;
        if (v[c].s == -1) {
            sv.push_back(V());
            csv(c);
            csi++;
        }
    }

    for (int i = 0; i < sv.size(); i++) {
        if (sv[i].b == -1) {
            cs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << sv[v[i].s].b << "\n";
    }
}
