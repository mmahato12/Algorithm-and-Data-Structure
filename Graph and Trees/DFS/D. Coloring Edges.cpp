//https://codeforces.com/contest/1217/problem/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

bool ans = 0;
int visit[5005],mark[5005];
vector <int> g[5005];

void dfs(int w, int t)
{
	if(visit[w] == 0)
		visit[w] = t;
	else
		return;
	for(auto &it: g[w])
		dfs(it, t + 1);
}

bool findLoop(int w)
{
    if(mark[w] == 1)
        return 1;
    if(mark[w] == 2)
        return 0;
    mark[w] = 1;
    for(auto &x: g[w])
    {
        if(findLoop(x))
            return 1;
    }
    mark[w]=2;
    return 0;
}

signed main()
{
    int n,m;
    bool flag=1;
    int u[5005],v[5005];
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u[i]>>v[i];
        g[u[i]].push_back(v[i]);
    }

    for(int i=1; i<=n; i++)
    {
        if(mark[i]==0 && findLoop(i))
        {
            flag=0;
            break;
        }
    }

    if(flag)
    {
        cout<<"1\n";
        for(int i=0; i<m; i++)
            cout<<"1 ";
        return 0;
    }
    
    for(int i=1; i<=n; i++)
    {
        if(visit[i] == 0)
            dfs(i, 1);
    }
    
    cout<<2<<"\n";
    for(int i=0; i<m; i++)
    {
        cout<<1 + (visit[v[i]] > visit[u[i]])<<" ";
    }
}