#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

struct swi {
    int age, like;
};

const int MAXN = 5e5 + 7;
swi s[MAXN];

bool comp(const swi &a, const swi &b) {
    if (a.like == b.like)
        return a.age > b.age;
    return a.like > b.like;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int w, k;
        cin >> w >> k;
        s[i].age = w;
        s[i].like = w / k + 1;
    }

    sort(s, s + n, comp);

    int res = 0;
    int cur = s[0].like;
    int i = 0;

    // for(int i = 0; i < n; i++){
    //     auto x = s[i];
    //     cout << x.age << " " << x.like << "\n";
    // }

    while (i < n) {
        while (i < n && s[i].age >= cur) {
            i++;
        }
        res++;
        cur = s[i].like;
    }

    cout << res;

    return 0;
}