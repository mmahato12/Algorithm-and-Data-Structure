//https://codeforces.com/problemset/problem/448/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
int n,m,k;

bool check(int x)
{
    int res=0;
    for(int i=1; i<=n; i++)
        res+=min(x/i, m);

    return res>=k;
}

int32_t main()
{
    FastIO;
    cin>>n>>m>>k;

    int l=1, r=n*m;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(check(m))
            r=m-1;
        else
            l=m+1;
    }

    cout<<r+1;
}