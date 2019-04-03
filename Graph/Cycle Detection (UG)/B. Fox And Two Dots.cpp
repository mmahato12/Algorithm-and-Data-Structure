//https://codeforces.com/problemset/problem/510/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int vi[105][105];
string s[55];
int n,m;
int ans;

void dfs(char c, int u, int v, int pu, int pv)
{
	if(u<0 || v<0 || u>=n || v>=m)
		return;
	if(pu>=0 && pv>=0 && s[pu][pv]!=s[u][v])
	    return;
//    cout<<s[u][v]<<" ";
//    cout<<u<<" "<<v<<"\n";
	if(vi[u][v])
	{
		ans=1;
		return;
	}
	
	vi[u][v]=1;
	if(pu!=u+1 || pv!=v)	
		dfs( c, u+1, v, u, v);
	if(pu!=u || pv!=v+1)
		dfs( c, u, v+1, u, v);
	if(pu!=u-1 || pv!=v)
		dfs( c, u-1, v, u, v);
	if(pu!=u || pv!=v-1)
		dfs( c, u, v-1, u, v);
}

int32_t main()
{
	FastIO;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>s[i];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(vi[i][j]==0)
			{
				dfs(s[i][j], i, j, -1, -1);
				if(ans)
				{
					cout<<"Yes";
					return 0;
				}
			}
		}
	}

	cout<<"No";
}