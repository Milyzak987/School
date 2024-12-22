#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 7;
vector<pll> graph[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        ans += c;
    }

    cout << ans << " ";
    for(int i = 1; i < n; i++){
        cout << 0 << " ";
    }
}