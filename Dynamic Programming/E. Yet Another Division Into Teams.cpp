//https://codeforces.com/contest/1256/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define ff first
#define ss second

int dp[200005];
int p[200005];
int t[200005];

signed main()
{
    FastIO;
    int n,a;
    cin>>n;
    vector <pair <int, int> > v;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back({a, i});
        p[i] = -1;
        dp[i+1] = 1e15;
    }
    
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++)
    {
        for(int j=3; j<=5 && i+j<=n; j++)
        {
            if(dp[i+j] > dp[i] + (v[i+j-1].ff - v[i].ff))
            {
                dp[i+j] = dp[i] + (v[i+j-1].ff - v[i].ff);
                p[i+j] = i;
            }
        }
    }
    
    int curr=n;
    int cnt=0;
    while(curr != 0)
    {
        for(int i=curr-1; i>=p[curr]; i--)
            t[v[i].ss] = cnt;
        cnt++;
        curr = p[curr];
    }
    
    cout<<dp[n]<<" "<<cnt<<"\n";
    for(int i=0; i<n; i++)
        cout<<t[i]+1<<" ";
}