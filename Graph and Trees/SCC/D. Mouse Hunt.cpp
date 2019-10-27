//https://codeforces.com/contest/1027/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
vector <int> g1[200005],g2[200005];
vector <int> group[200005];
stack <int> s;
int n,k=1;
int deg[200005];
int comp[200005];
bool mark[200005];
 
void dfs1(int u)
{
    mark[u] = 1;
    for(auto &x: g1[u])
        if(mark[x] == 0)
            dfs1(x);
    s.push(u);
}
 
void dfs2(int u, int k)
{
    comp[u] = k;
    group[k].push_back(u);
    for(auto &x: g2[u])
        if(comp[x] == 0)
            dfs2(x, k);
}
 
void scc()
{
    for(int i=1; i<=n; i++)
    {
        if(mark[i] == 0)
            dfs1(i);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(comp[s.top()] == 0)
            dfs2(s.top(), k++);
        s.pop();
    }
}
 
signed main()
{
    int a;
    cin>>n;
    int cost[n+5];
        
    for(int i=1; i<=n; i++)
        cin>>cost[i];
        
    for(int i=0; i<n; i++)
    {
        cin>>a;
        g1[i+1].push_back(a);
        g2[a].push_back(i+1);
    }
 
    scc();
    
    for(int i=1; i<=n; i++)
    {
        for(auto &x: g1[i])
            if(comp[i] != comp[x])
                deg[comp[i]]++;
    }
    
    int ans=0;
    for(int i=1; i<=k; i++)
    {
        if(!deg[i])
        {
            int curr = INT_MAX;
            for(auto &x: group[i])
                curr = min(curr, cost[x]);
            
            if(curr != INT_MAX)
                ans += curr;
        }
    }
 
    cout<<ans;
}