//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/d-30/
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,ans=0;
        cin>>n>>k;
        int a[n+5],pref[n+5]={};
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            pref[i]=pref[i-1]+a[i];
        }
    
        sort(pref, pref+n+1);
    
        for(int i=0; i<n; i++)
        {
            int up=upper_bound(pref, pref+n+1, k+pref[i]) - pref;
            ans+=(n+1)-up;
//            cout<<up<<" "<<pref[i]<<"\n";
        }
    
        cout<<ans<<"\n";
    }
}