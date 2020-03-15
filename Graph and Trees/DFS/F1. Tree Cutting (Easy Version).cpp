#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int red,blue,ans;
int a[300005];
vector <int> g[300005];

pair <int, int> dfs(int u, int p=-1)
{
	int r = (a[u] == 1);
	int b = (a[u] == 2);
	for(auto &x: g[u])
	{
		if(x != p)
		{
			auto tmp = dfs(x, u);
			ans += (tmp.first==0 && tmp.second==blue);
			ans += (tmp.first==red && tmp.second==0);
			r += tmp.first;
			b += tmp.second;
		}
	}

	return make_pair(r, b);
}

signed main()
{
    FastIO;
    int n;
    int x,y;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
    	cin>>a[i];
    	if(a[i] == 1) red++;
    	if(a[i] == 2) blue++;
    }

    for(int i=1; i<n; i++)
    {
    	cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    
    dfs(1);

    cout<<ans;
}