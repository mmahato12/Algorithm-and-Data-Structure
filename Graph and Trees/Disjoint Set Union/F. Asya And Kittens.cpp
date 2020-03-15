//https://codeforces.com/problemset/problem/1131/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int parent[200005];
vector <int> v[200005];

int find(int x)
{
	if(parent[x] == x)
		return x;

	parent[x] = find(parent[x]);
	return parent[x];
}

void Union1(int x, int y)
{
	x = find(x);
	y = find(y);
	if(v[x].size() > v[y].size())
		swap(x, y);

	parent[x] = y;
	for(auto &it: v[x])
		v[y].push_back(it);
	v[x].clear();
}

signed main()
{
    FastIO;
    int n,x,y;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
    	parent[i] = i;
    	v[i].push_back(i);
    }

    for(int i=1; i<n; i++)
    {
    	cin>>x>>y;
    	Union1(x, y);
    }

    for(int i=1; i<=n; i++)
    	for(auto &x: v[i])
    		cout<<x<<" ";
}