//https://codeforces.com/contest/1324/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[200005];
int dp[200005];
int ans[200005];
vector <int> g[200005];

void dfs1(int u, int p=-1)
{
    dp[u] = ((a[u] == 0) ? -1 : +1);
    for(auto &x: g[u])
    {
        if(x == p) continue;
        dfs1(x, u);
        dp[u] += max(dp[x], 0ll);
    }
}

void dfs2(int u, int p=-1)
{
    ans[u] = dp[u];
    for(auto &x: g[u])
    {
        if(x == p) continue;
        dp[u] -= max(dp[x], 0ll);
        dp[x] += max(dp[u], 0ll);
        dfs2(x, u);
        dp[x] -= max(dp[u], 0ll);
        dp[u] += max(dp[x], 0ll);
    }
}

signed main()
{
    FastIO;
    int u,v,n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<n; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1);
    dfs2(1);
    
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}