//https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/tutorial/
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int N=20;
vector <int> g[N];
deque <int> v;
bool visit[N];

void dfs(int u)
{
    visit[u]=true;
    for(auto &x: g[u])
        if(visit[x]==false)
            dfs(x);
    
    v.push_front(u);
}

signed main()
{
    FastIO;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
    }
    
    for(int i=1; i<=n; i++)
        sort(g[i].rbegin(), g[i].rend());
    
    for(int i=n; i>=1; i--)
        if(visit[i]==false)
            dfs(i);

    for(auto &x: v)
        cout<<x<<" ";
    
}