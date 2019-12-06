//https://www.codechef.com/NOV19A/problems/FAILURE
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MAXN = 1e5 + 5;

unordered_set <int> g[MAXN];
vector <pair<int, int> > allbridges;
int n,m;

bool dfs1(int u, bool mark[], int parent)
{
    mark[u] = true;
    for(auto &x: g[u])
    {
//        cout<<u<<" "<<x<<"\n";
        if(!mark[x])
        {
            if(dfs1(x, mark, u))
                return true;
        }
        else if(x != parent)
            return true;
    }
    return false;
}

bool isCycle()
{
    bool mark[n+5];
    for(int i=1; i<=n; i++)
        mark[i] = false;

    for(int i=1; i<=n; i++)
        if(!mark[i] && dfs1(i, mark, -1))
            return true;
    return false;
}

void bridges(int u, bool mark[], int disc[], int low[], int parent[])
{
    static int time = 0;
    mark[u] = true;
    disc[u] = low[u] = ++time;

    for(auto &x: g[u])
    {
        if(!mark[x])
        {
            parent[x] = u;
            bridges(x, mark, disc, low, parent);

            low[u] = min(low[u], low[x]);

            if(low[x] > disc[u])
                allbridges.push_back({u, x});
        }
        else if(x != parent[u])
            low[u] = min(low[u], disc[x]);
    }
}

void find_bridges()
{
    bool mark[n+5];
    int disc[n+5];
    int low[n+5];
    int parent[n+5];

    for(int i=0; i<=n; i++)
    {
        parent[i] = -1;
        mark[i] = false;
    }

    for(int i=1; i<=n; i++)
        if(mark[i] == false)
            bridges(i, mark, disc, low, parent);
}

signed main()
{
    FastIO;
    int T;
    int u,v;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        allbridges.clear();
        for(int i=0; i<=n; i++)
            g[i].clear();

        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            g[u].insert(v);
            g[v].insert(u);
        }

        if(!isCycle())
        {
            cout<<"-1\n";
            continue;
        }

        find_bridges();
        
//        cout<<allbridges.size()<<".\n";
        for(auto &x: allbridges)
        {
//            cout<<x.first<<" "<<x.second<<"\n";
            g[x.first].erase(x.second);
            g[x.second].erase(x.first);
        }

        int mx=-1, edge=0;
        for(int i=1; i<=n; i++)
        {
//          cout<<mx<<" "<<g[i].size()<<"<\n";
            if(mx < (int)g[i].size())
            {
                mx = (int)g[i].size();
                edge = i;
            }
        }

//        cout<<edge<<":\n";
        for(auto &x: g[edge])
            g[x].erase(edge);
        g[edge].clear();

        if(isCycle())
            cout<<"-1\n";
        else
            cout<<edge<<"\n";
    }
}