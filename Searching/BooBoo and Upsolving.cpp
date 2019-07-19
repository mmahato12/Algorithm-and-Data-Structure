//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/booboo-and-upsolving-circuits/
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int n,m,a[100005];
    int sum=0,mx=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mx=max(mx, a[i]);
        sum+=a[i];
    }
    
    int lo=mx,hi=sum;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        int cur=0,req_days=1;
        for(int i=0; i<n; i++)
        {
            if(cur+a[i]<=mid)
                cur+=a[i];
            else
            {
                cur=a[i];
                req_days++;
            }
        }

        if(req_days<=m)
            hi=mid;
        else
            lo=mid+1;
    }

    cout<<lo;    
}