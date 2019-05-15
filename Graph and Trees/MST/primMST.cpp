#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

using namespace std;
const int MAX = 1e5 + 5;
typedef pair<int, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

int prim(int x)
{
	priority_queue <PII, vector<PII>, greater<PII> > Q;
	int y;
	int mincost=0;
	PII p;
	Q.push({0, x});
	while(Q.size())
	{
		p=Q.top();
		Q.pop();
		x=p.second;
		if(marked[x]==true)
			continue;

		mincost+=p.first;
		marked[x]=true;
		for(int i=0; i<adj[x].size(); i++)
		{
			y=adj[x][i].second;
			if(marked[y]==false)
				Q.push(adj[x][i]);
		}
	}

	return mincost;
}

signed main()
{
	int x,y,nodes,edges;
	int weight,cost,mincost;
	cin>>nodes>>edges;
	for(int i=0; i<edges; i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back({weight, y});
		adj[y].push_back({weight, x});
	}

	mincost=prim(1);
	cout<<mincost<<endl;

	return 0;
}