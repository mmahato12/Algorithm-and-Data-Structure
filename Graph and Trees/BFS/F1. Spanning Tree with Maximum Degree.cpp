//https://codeforces.com/contest/1133/problem/F1
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

vector <int> v[200005];
vector <pair<int, int> > d,ans;
int mark[200005], cnt[200005];

int32_t main()
{
	FastIO;
	int n,m,a,b;
	int maxd=0,maxx=0;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i=1; i<=n; i++)
	    d.push_back({cnt[i], i});

	sort(d.rbegin(), d.rend());
	for(auto &u: d)
	{
//	    cout<<u.second<<" "<<u.first<<"-\n";
		if(mark[u.second]==0)
		{
			queue <int> q;
			q.push(u.second);
			mark[u.second]=1;
			while(q.size())
			{
				int tmp=q.front();
				q.pop();
				for(auto &x: v[tmp])
				{
					if(mark[x]==0)
					{
						mark[x]=1;
						q.push(x);
						ans.push_back({tmp, x});
					}
				}
			}
		}
	}

	for(auto &x: ans)
		cout<<x.first<<" "<<x.second<<"\n";
}