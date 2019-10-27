//https://codeforces.com/contest/1046/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n;
    cin>>n;
    int x,f;
    int a[n+5];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>x>>f;
    
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int p = a[i];
        if(p > x)
            ans += (p-x)/(x+f) + ((p-x)%(x+f) !=0);
    }

    cout<<ans*f;
}