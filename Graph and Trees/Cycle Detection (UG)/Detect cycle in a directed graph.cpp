//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?track=md-graph&batchId=144

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

bool ans = 0;
int visit[100005];

void dfs(int x, vector<int> adj[], int c)
{
    visit[x] = 1;
    for(int i=0; i<adj[x].size(); i++)
    {
      //  cout<<x<<" "<<adj[x][i]<<"\n";
        if(visit[adj[x][i]] == 1)
        {
            ans = 1;
            return;
        }
        else
            dfs(adj[x][i], adj, c);
    }
    
    visit[x] = 2;
}

bool isCyclic(int V, vector<int> adj[])
{
    ans = 0;
    for(int i=0; i<V; i++)
        visit[i]=-1;
    for(int i=0; i<V; i++)
    {
        if(visit[i] == -1)
            dfs(i, adj, i);
    }
    
    return ans;
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x,y;
        int V,E;
        vector<int> adj[100005];
        cin>>V>>E;
        for(int i=0; i<E; i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
        }
        
        if(isCyclic(V, adj))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}