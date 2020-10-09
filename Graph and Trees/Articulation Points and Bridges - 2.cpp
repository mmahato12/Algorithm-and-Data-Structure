#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int V,E;
int parent[15];
int low[15], disc[15];
bool visited[15];
vector <int> ans1;
vector <int> g[15];
vector < pair<int, int> > ans2;

bool comp(pair <int , int> a, pair <int , int> b)
{
    if(a.first < b.first)
        return true;
    else if(a.first == b.first && a.second < b.second)
        return true;
    return false;
}

void dfs1(int u)
{
	static int time1 = 0;
	int child = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time1;
	for(auto &v: g[u])
	{
		if(visited[v] == false)
		{
			child += 1;
			parent[v] = u;
			dfs1(v);
			low[u] = min(low[u], low[v]);
			if(parent[u] == -1 && child > 1)
				ans1.push_back(u);
			if(parent[u] != -1 && low[v] >= disc[u])
				ans1.push_back(u);
		}
		else if(parent[u] != v)
			low[u] = min(low[u], disc[v]);
	}
}

void ArticulationPoint()
{
	memset(parent, -1, sizeof(parent));
	memset(visited, false, sizeof(visited));
	for(int i=0; i<V; i++)
		if(visited[i] == false)
			dfs1(i);
}

void dfs2(int u)
{
	static int time2 = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time2;
	for(auto &v: g[u])
	{
		if(visited[v] == false)
		{
			parent[v] = u;
			dfs2(v);
			low[u] = min(low[u], low[v]);
			if(low[v] > disc[u])
				ans2.push_back({u, v});
		}
		else if(parent[u] != v)
			low[u] = min(low[u], disc[v]);
	}
}

void find_bridges()
{
	memset(parent, -1, sizeof(parent));
	memset(visited, false, sizeof(visited));
    for(int i=0; i<V; i++)
		if(visited[i] == false)
			dfs2(i);
}

signed main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int x,y;
    cin>>V>>E;
    for(int i=0; i<E; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    
    ArticulationPoint();
    find_bridges();

    sort(ans1.begin(), ans1.end());
    cout<<ans1.size()<<"\n";
    for(auto &x: ans1)
        cout<<x<<" ";
    cout<<"\n";
    
    sort(ans2.begin(), ans2.end(), comp);
    cout<<ans2.size()<<"\n";
    for(auto &x: ans2)
        cout<<x.first<<" "<<x.second<<"\n";
}