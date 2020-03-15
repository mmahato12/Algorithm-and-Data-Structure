//https://codeforces.com/contest/1143/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int res=1;
vector <int> ans;
vector <pair <int, int> > g[100005];

void dfs(int u, int w)
{
    res = w;
    for(auto &x: g[u])
        res = res & x.second;

    if(res == 1)
        ans.push_back(u);
    
	for(auto &x: g[u])
	{
		dfs(x.first, x.second);
//	    cout<<x.first<<" "<<x.second<<" "<<res<<"\n";
	}
}

signed main()
{
    FastIO;
    int n,p,w,v;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
    	cin>>v>>w;
    	if(v == -1)
    		p = i;
    	else
	    	g[v].push_back({i, w});
    }

    dfs(p, 0);
    
    if(ans.size())
    {
        sort(ans.begin(), ans.end());
        for(auto &x: ans)
            cout<<x<<" ";
    }
    else
        cout<<"-1";
}
S