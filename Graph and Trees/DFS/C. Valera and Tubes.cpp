#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int n,m,k;
int l=1,c;
int v[500][500];
vector < pair<int,int> > ans[100005];

void dfs(int x, int y)
{
	if(x<1 || y<1 || x>n || y>m)
		return;
	if(v[x][y])
	    return;
	c++;
	if(c>2 && l<k)
	{
		l++;
		c=1;
	}
		
	v[x][y]=l;
	ans[l].push_back({x, y});
	dfs(x+1, y);
	dfs(x, y+1);
	dfs(x-1, y);
	dfs(x, y-1);
}

int32_t main()
{
	FastIO;
	cin>>n>>m>>k;
	
	dfs(1, 1);
	for(int i=1; i<=k; i++)
	{
	    cout<<ans[i].size()<<" ";
	    for(auto &x : ans[i])
	        cout<<x.first<<" "<<x.second<<" ";
	    cout<<"\n";
	}
}