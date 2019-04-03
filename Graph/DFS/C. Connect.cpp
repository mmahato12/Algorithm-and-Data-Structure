//https://codeforces.com/contest/1130/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

bool v[55][55];
int c1,c2,r1,r2;
int d,k,minn;
vector < pair<int, int> > vp[55];

int dfs(int cr, int cc)
{
	vp[k].push_back({cr, cc});

	if(v[cr+1][cc]==1)
	{
		v[cr+1][cc]=0;
		dfs(cr+1, cc);
	}
	if(v[cr][cc+1]==1)
	{
		v[cr][cc+1]=0;
		dfs(cr, cc+1);
	}
	if(v[cr-1][cc]==1)
	{
		v[cr-1][cc]=0;
		dfs(cr-1, cc);
	}
	if(v[cr][cc-1]==1)
	{
		v[cr][cc-1]=0;
		dfs(cr, cc-1);
	}
}

int32_t main()
{
	FastIO;
	int n;
	string s[55];
	cin>>n;
	cin>>r1>>c1;
	cin>>r2>>c2;

	minn=pow(r1-r2,2) + pow(c1-c2, 2);

	for(int i=1; i<=n; i++)
	{
	    cin>>s[i];
		for(int j=0; j<n; j++)
			v[i][j+1]=1-(s[i][j]-'0');
	}
    v[r1][c1]=0;
	dfs(r1, c1);
	k++;
	v[r2][c2]=0;
	dfs(r2, c2);
	for(int i=0; i<vp[0].size(); i++)
	{
		for(int j=0; j<vp[1].size(); j++)
		{
			r1=vp[0][i].first;
			c1=vp[0][i].second;
			r2=vp[1][j].first;
			c2=vp[1][j].second;
			d=pow(r1-r2,2) + pow(c1-c2, 2);
			minn=min(d, minn);
		}
	}
	cout<<minn;
}