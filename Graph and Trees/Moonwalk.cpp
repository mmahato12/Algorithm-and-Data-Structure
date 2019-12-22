//https://www.codechef.com/problems/MNWLK
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int cu,cv,ce;
int mark[400005];
vector <pair <int, int> > g[400005];
pair <int, int> p[400005];

void dfs(int u)
{
    mark[u] = 1;
    for(auto v: g[u])
    {
        if(v != p[u])
        {
            if(mark[v.first] == 1)
            {
                cu = u, cv = v.first, ce = v.second;
            }
            else if(mark[v.first]==0)
            {
                p[v.first] = {u, v.second};
                dfs(v.first);
            }
        }
    }
    mark[u] = 2;
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,u,v;
        cin>>n>>m;
        for(int i=0; i<=2*n; i++)
        {
            g[i].clear();
            p[i] = {0, 0};
            mark[i] = 0;
        }

        for(int i=1; i<=m; i++)
        {
            cin>>u>>v;
            g[u].push_back({v+n, i});
            g[v+n].push_back({u, i});
        }

        cu=0, cv=0, ce=0;
        for(int i=1; i<=2*n; i++)
        {
            if(mark[i])
                continue;

            dfs(i);

            if(cu && cv)
                break;
        }
        
        if(cu && cv)
        {
            vector <int> vv = {ce};
            while(cu != cv)
            {
                vv.push_back(p[cu].second);
                cu = p[cu].first;
            }

            if(cv > n)
            {
                vv.push_back(ce);
                vv.erase(vv.begin());
            }
            
            cout<<":)\n";
            cout<<vv.size()<<"\n";
            for(auto &x: vv)
                cout<<x<<" ";
            cout<<"\n";
        }
        else
            cout<<":(\n";
    }
}