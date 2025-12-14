#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int POINT = 1;
const int QUERY = 2;
const int END = 3;
const int START = 4;

struct Event {
    int x, type, index, y1, y2 = -1;
};

bool operator<(Event& e1, Event& e2) {
    return tie(e1.x, e1.type, e1.index, e1.y1, e1.y2) < tie(e2.x, e2.type, e2.index, e2.y1, e2.y2);
}

const int MAX = 1000 * 1000;
Event events[4 * MAX + 10];
pii points[MAX + 1];
pair<pii, pii> rectangles[MAX + 1];
vector<int> graph[MAX + 1];
bool visited[MAX + 1];
int dist[MAX + 1];
set<pii> activeSet;
queue<int> q;

int setupEvents(int n, int m, bool swapCoords) {
    int size = 0;

    for (int i = 1; i <= m; i++) {
        if (swapCoords) swap(points[i].first, points[i].second);
        events[++size] = {points[i].first, POINT, i, points[i].second};
    }

    for (int i = 1; i <= n; i++) {
        if (swapCoords) swap(rectangles[i].first, rectangles[i].second);
        events[++size] = {rectangles[i].first.first, QUERY, i, rectangles[i].second.first, rectangles[i].second.second};
        events[++size] = {rectangles[i].first.first, START, i, rectangles[i].second.first, rectangles[i].second.second};
        events[++size] = {rectangles[i].first.second, END, i, rectangles[i].second.first, rectangles[i].second.second};
    }

    return size;
}

pii solve(int n, int m, bool swapCoords) {
    int size = setupEvents(n, m, swapCoords);

    sort(events + 1, events + 1 + size);

    int startNode = -1, targetNode = -1;

    for (int i = 1; i <= size; i++) {
        Event& e = events[i];

        if (e.type == POINT) {
            int nodeIndex = activeSet.upper_bound({e.y1, 0})->second;

            if (e.index == 1) {
                startNode = nodeIndex;
            } else if (e.index == 2) {
                targetNode = nodeIndex;
            } else {
                visited[nodeIndex] = true;
            }
        } else if (e.type == QUERY) {
            auto begin = activeSet.upper_bound({e.y1, 0});
            auto end = activeSet.lower_bound({e.y2, 0});

            for (; begin != activeSet.end() && begin != next(end); begin++) {
                if (begin->first == e.y1) continue;

                graph[e.index].push_back(begin->second);
                graph[begin->second].push_back(e.index);
            }
        } else if (e.type == START) {
            activeSet.insert({e.y2, e.index});
        } else if (e.type == END) {
            activeSet.erase({e.y2, e.index});
        }
    }

    return {startNode, targetNode};
}

void bfs(int start) {
    dist[start] = 1;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (visited[neighbor]) continue;

            dist[neighbor] = dist[current] + 1;
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int w, h, n, m;
    cin >> w >> h >> n >> m;

    cin >> points[1].first >> points[1].second;
    cin >> points[2].first >> points[2].second;

    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        rectangles[i] = {{x1, x2}, {y1, y2}};
    }

    m += 2;
    for (int i = 3; i <= m; i++) {
        cin >> points[i].first >> points[i].second;
    }

    pii startTarget = solve(n, m, false);

    solve(n, m, true);

    bfs(startTarget.first);

    cout << dist[startTarget.second];

    return 0;
}
