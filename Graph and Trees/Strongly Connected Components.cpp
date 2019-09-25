//https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int cnt;
bool mark[55];
vector <int> g1[25],g2[25];
stack <int> s;

void dfs1(int u)
{
    mark[u] = 1;
    for(auto &x: g1[u])
    {
        if(mark[x] == 0)
            dfs1(x);
    }
    s.push(u);
}

void dfs2(int u)
{
    mark[u] = 1;
    ++cnt;
    for(auto &x: g2[u])
    {
        if(mark[x] == 0)
            dfs2(x);
    }
}

signed main()
{
    FastIO;
    int ans=0;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        g1[x].push_back(y);
        g2[y].push_back(x);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(mark[i] == 0)
            dfs1(i);
    }
    
    for(int i=1; i<=n; i++)
        mark[i] = 0;

    for(int i=0; i<n; i++)
    {
        int x = s.top();
        if(mark[x] == 0)
        {
            cnt=0;
            dfs2(x);
            if(cnt%2)
                ans += cnt;
            else
                ans -= cnt;
        }
        s.pop();
    }

    cout<<ans;
}