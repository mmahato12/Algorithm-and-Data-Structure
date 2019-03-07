//https://codeforces.com/problemset/problem/377/A
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

string s[505];
int x;
int n,m,k;
int vi[505][505];

void check(int u, int v)
{
	if(x<k)
	{
		s[u][v]='X';
		x++;
	}
}

void dfs(int u, int v)
{
	if(u<0 || v<0 || u>=n || v>=m)
		return;
	if(vi[u][v] || s[u][v]=='#' || x==k)
		return;
    
//    cout<<u<<" "<<v<<"\n";
	vi[u][v]=1;

	dfs(u+1, v);

	dfs(u, v+1);

	dfs(u-1, v);

	dfs(u, v-1);
	check(u, v);
}

int32_t main()
{
	FastIO;
	cin>>n>>m>>k;
	for(int i=0; i<n; i++)
		cin>>s[i];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
		{
			if(vi[i][j]==0)
				dfs(i, j);
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			cout<<s[i][j];
		cout<<"\n";
	}
}