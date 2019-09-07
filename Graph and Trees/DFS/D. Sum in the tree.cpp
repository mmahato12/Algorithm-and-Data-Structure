//https://codeforces.com/contest/1099/problem/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int ans;
int s[100005],minn[100005];
vector <int> g[100005];

void dfs(int u, bool par, int ps)
{
//    cout<<u<<" "<<par<<": "<<s[u]<<" "<<ps;
	if(par)
	{
//	    cout<<";";
		if(ps > s[u])
		{
			cout<<"-1";
			exit(0);
		}

		ans += s[u] - ps;
	}
//    cout<<" = "<<ans<<"\n";
	for(auto &x: g[u])
	{
		if(par)
			ps = s[u];
		dfs(x, 1^par, ps);
		if(!par)
			minn[u] = min(s[x] - ps, minn[u]);
	}
}

signed main()
{
    FastIO;
	int n,p;
	cin>>n;
	for(int i=2; i<=n; i++)
	{
		cin>>p;
		if(i != 1)
			g[p].push_back(i);
	}

	for(int i=1; i<=n; i++)
	{
		cin>>s[i];
		minn[i] = INT_MAX;
	}

	dfs(1, 1, 0);

	for(int i=1; i<=n; i++)
	{
		if(minn[i] != INT_MAX)
			ans -= ((int)g[i].size() - 1)*minn[i];
	}

	cout<<ans;
}