//https://codeforces.com/problemset/problem/1046/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int n,x,f;
int a[200005];
 
bool check(int num, int d)
{
    return (num - ((x+f)*d) <= x);
}

signed main()
{
    FastIO;
    cin>>n;
    int ans=0;
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>x>>f;
 
    for(int i=0; i<n; i++)
    {
        int lo = 0, hi = 1e9;
        while(lo < hi)
        {
            int mid = (lo + hi)/2;
            if(check(a[i], mid))
                hi = mid;
            else
                lo = mid+1;
//            cout<<"("<<lo<<", "<<hi<<") ";
        }
        ans += hi;
    }
 
    cout<<ans*f;
}