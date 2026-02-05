#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Box {
    int id;
    ll w;
    ll m;
    ll s;
};

const int MAXN = 2e5 + 7;
vector<Box> boxes(MAXN);

bool comp(const Box& a, const Box& b) { return a.s < b.s; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> boxes[i].w >> boxes[i].m;
        boxes[i].id = i;

        boxes[i].s = boxes[i].w + boxes[i].m;
    }

    sort(boxes.begin(), boxes.begin() + n, comp);

    priority_queue<ll> pq;
    ll cur = 0;

    for (int i = 0; i < n; i++) {
        pq.push(boxes[i].m);
        cur += boxes[i].m;

        if (cur > boxes[i].s) {
            ll heaviest = pq.top();
            pq.pop();
            cur -= heaviest;
        }
    }

    cout << pq.size();
}