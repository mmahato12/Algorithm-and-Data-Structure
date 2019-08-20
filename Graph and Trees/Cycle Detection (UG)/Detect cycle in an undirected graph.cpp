//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

bool ans;
bool visit[100005];
void dfs(int u, int p, vector<int> adj[])
{
    visit[u] = 1;
//    cout<<u<<" "<<p<<"\n";
    for(auto &x: adj[u])
    {
        if(visit[x] == 1 && p!=x)
        {
            ans = 1;            
            return;
        }
        else if(visit[x]==0 && p!=x)
            dfs(x, u, adj);
    }
}

bool isCyclic(vector<int> adj[], int V)
{
    ans=0;
    for(int i=0; i<V; i++)
        visit[i]=0;
    
    for(int i=0; i<V; i++)
    {
        if(visit[i] == 0)
            dfs(i, -1, adj);
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
            adj[y].push_back(x);
        }
        if(isCyclic(adj, V))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}