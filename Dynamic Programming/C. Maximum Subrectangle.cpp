//https://codeforces.com/contest/1060/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int n,m,x;
    cin>>n>>m;
    int a[n+5]={},b[m+5]={};
    int aa[n+5]={},bb[m+5]={},ans=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[i]=a[i-1]+a[i];
        aa[i]=1e18;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
        b[i]=b[i-1]+b[i];
        bb[i]=1e18;
    }
    cin>>x;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            aa[i-j]=min(aa[i-j], a[i]-a[j]);
//            cout<<aa[i-j]<<" ";
        }
//        cout<<"\n";
    }
//    cout<<"\n";
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<i; j++)
        {
            bb[i-j]=min(bb[i-j], b[i]-b[j]);
//            cout<<bb[i-j]<<" ";
        }
//        cout<<"\n";
    }
//    cout<<"\n";

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(aa[i]*bb[j]<=x)
                ans=max(i*j, ans);
//            cout<<aa[i]*bb[j]<<" ";
        }
//        cout<<"\n";
    }
//    cout<<"\n";

    cout<<ans;
}