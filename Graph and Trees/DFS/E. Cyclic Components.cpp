//https://codeforces.com/contest/977/problem/E

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
vector<int> v[200005];
bool flag,used[200005];
int nodes;
 
void dfs(int x)
{
	if(used[x])
		return;
//    cout<<v[x].size()<<" ";
    used[x]=true;
    nodes++;
	flag&=(v[x].size()==2);
	for(auto it:v[x])
		dfs(it);
}
 
int32_t main()
{
	int n,m,x,y,ans=0;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1; i<=n; i++)
	{
	    if(used[i])
	        continue;
		flag=true;
		nodes=0;
		dfs(i);
		if(flag && nodes>=3)
			ans++;
//		cout<<"n: "<<nodes<<flag<<"\n";
	}
	cout<<ans;
}