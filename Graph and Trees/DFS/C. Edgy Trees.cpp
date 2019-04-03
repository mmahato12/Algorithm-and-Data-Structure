//https://codeforces.com/contest/1139/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MOD=1e9+7;

int cnt;
bool mark[200005];
vector <int> g[200005];
map < pair<int, int>, int> h;

void dfs(int u, int v)
{
    if(u!=v && h[{u,v}]!=1ll)
        return;
    
    mark[v]=true;
    cnt++;
    for(auto &x: g[v])
    {
        if(mark[x]==false)
            dfs(v, x);
    }
}

int32_t main()
{
    FastIO;
    int n,k,u,v,w;
    int ans=1, tmp;
    cin>>n>>k;
    for(int i=0; i<k; i++)
        ans=(ans*n)%MOD;
    
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v>>w;
        h[{u,v}]=w+1;
        h[{v,u}]=w+1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cnt=0,tmp=1;
        if(mark[i]==false)
        {
            dfs(i, i);
            for(int j=0; j<k; j++)
                tmp=(tmp*cnt)%MOD;

            ans=(ans-tmp+MOD)%MOD;
        }
    }

    cout<<ans;
}