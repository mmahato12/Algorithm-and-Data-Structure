#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MAXX=1e6+5;
vector < pair<int, int> > v[MAXX];
int dist[MAXX];
bool vis[MAXX];

signed main()
{
    FastIO;
    int n,m;
    int from,next,weight;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>from>>next>>weight;
        v[from].push_back({weight, next});
//        v[next].push_back({weight, from});
    }
    
    for(int i=0; i<MAXX; i++)
        dist[i]=1e18;

    multiset <pair<int, int> > s;
    dist[1]=0;
    s.insert({0, 1});
    while(s.size())
    {
    	pair<int, int> p=*s.begin();
    	s.erase(s.begin());

    	from=p.second;
    	weight=p.first;

    	if(vis[from])
    		continue;

    	vis[from]=true;

    	for(auto &it: v[from])
    	{
    		next=it.second;
    		weight=it.first;
    		if(dist[from] + weight < dist[next])
    		{
    			dist[next] = dist[from] + weight;
    			s.insert({dist[next], next});
    		}
    	}
    }

    for(int i=2; i<=n; i++)
        cout<<dist[i]<<" ";

}