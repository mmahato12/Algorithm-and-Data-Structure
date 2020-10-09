//https://codeforces.com/contest/1384/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
	int n;
    string s, t;
    cin>>n>>s>>t;

    bool mark[25] = {0};
    vector <int> g[20];
    bool bad = false;

    for(int i=0; i<n; i++)
    {
    	int ss = s[i]-'a';
    	int tt = t[i]-'a';
    	if(ss > tt)
    		bad = true;

    	g[ss].push_back(tt);
    	g[tt].push_back(ss);
    }

    if(bad)
    {
    	cout<<"-1\n";
    	return;
    }

    int ans = 0;
    function<void(int)> dfs = [&](int u)
    {
    	mark[u] = true;
    	for(auto v: g[u])
    		if(!mark[v])
    			ans+=1, dfs(v);
    };

    for(int i=0; i<20; i++)
    {
    	if(!mark[i])
    		dfs(i);
    }

    cout<<ans<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
    cin>>T;
    while(T--)
        solve();
}