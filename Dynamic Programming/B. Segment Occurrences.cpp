//https://codeforces.com/problemset/problem/1016/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    string s,t;
    int n,m,q,l,r;
    int dp[100005]={0};
    vector <int> v;
    cin>>n>>m>>q;
    cin>>s>>t;

    for(int i=0; i<n; i++)
    {
        bool flag=1;
        for(int j=0; j<m; j++)
            if(s[i+j]!=t[j])
                flag=0;
        if(i+m-1<n)
            dp[i+1]=dp[i]+flag;
        else
        dp[i+1]=dp[i];
    }
/*    
    for(int i=1; i<=n; i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
*/
    while(q--)
    {
        cin>>l>>r;
        r-=m-1;
//        cout<<l<<" "<<r<<": ";
        if(r<l)
            cout<<0<<"\n";
        else
            cout<<dp[r]-dp[l-1]<<"\n";
    }
}