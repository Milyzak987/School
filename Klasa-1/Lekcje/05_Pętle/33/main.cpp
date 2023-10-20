#include <iostream>
using namespace std;

int N, M;

int main()
{
    cin >> N;
    cin >> M;
    if(N<M)
    {
        for(int i=N; i<=M; i++)
            cout << i << " ";

    }
    else
    {
        for(int i=N; i>=M; i--)
            cout << i << " ";
    }
}
