#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
set <int> v[101];
bool visit[101];

int dfs(int x, int n)
{
	visit[x]=1;
	for(int i=0; i<n; i++)
	{
		if(visit[i])
            continue;
            
		for(set <int> :: iterator j=v[i].begin(); j!=v[i].end(); j++)
		{
			if(v[x].count(*j))
			{
				dfs(i, n);
				break;
			}
		}
	}
}

int32_t main()
{
    int m,n,k,d,kt=0;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>k;
		kt+=k;
		for(int j=0; j<k; j++)
		{
			cin>>d;
			v[i].insert(d);
		}
	}

    int ans=(kt==0) ? 0 : -1;
	for(int i=0; i<n; i++)
	{
		if(visit[i]==0)
		{
			dfs(i, n);
			ans++;
		}
	}

	cout<<ans;
}
