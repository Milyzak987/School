#include<iostream>
using namespace std;

int main()
{
    int n, q, a, b;
    int seq[1000000], sum_pref[1000001];
    cin >> n >> q;

    sum_pref[0]=0;
    for(int i=0; i<n; i++)
    {
        cin >> seq[i];
        sum_pref[i+1] = sum_pref[i]+seq[i];
    }

    for (int i=0; i<q; i++)
    {
        cin >> a >> b;
        cout << sum_pref[b]-sum_pref[a-1] << endl;
    }
}