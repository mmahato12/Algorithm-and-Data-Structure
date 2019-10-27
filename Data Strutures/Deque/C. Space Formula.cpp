//https://codeforces.com/contest/1046/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n,d;
    cin>>n>>d;
    int a[n+5],p[n+5];
    deque <int> dq;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i != d-1)
            dq.push_back(a[i]);
    }

    for(int i=0; i<n; i++)
        cin>>p[i];

    int rank=1;
    for(int i=1; i<n; i++)
    {
        if(p[0] + a[d-1] >= dq.back() + p[i])
            dq.pop_back();
        else if(p[0] + a[d-1] < dq.front() + p[i])
        {
            dq.pop_front();
            rank++;
        }
        else
            dq.pop_front();
    }

    cout<<rank;
}