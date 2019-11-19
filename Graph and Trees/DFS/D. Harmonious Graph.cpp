//https://codeforces.com/contest/1253/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int mx,mn;
bool mark[200005];
vector <int> g[200005];
vector <pair<int, int> > v;

bool comp (pair <int,int> a, pair <int,int> b)
{
    if(a.first < b.first)
        return true;
    if(a.first == b.first && a.second < b.second)
        return true;
    return false;
}

void dfs(int u)
{
    mark[u] = 1;
    mx = max(mx, u);
    mn = min(mn, u);
    for(auto &x: g[u])
    {
        if(mark[x] == 0)
            dfs(x);
    }
}

signed main()
{
    FastIO;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1; i<=n; i++)
    {
        if(mark[i] == 0)
        {
        	mx=-1e9;mn=1e9;
            dfs(i);            
            v.push_back({mn,mx});
        }
    }

    sort(v.begin(), v.end(), comp);

    int ans=0;
    int i=0;
    while(i < v.size())
    {
    	bool flag = 1;
    	int tmp = 0;
        int ff = v[i].first;
        int ss = v[i].second;
//        cout<<ff<<" "<<ss<<" : "<<ans<<"\n";
        while(i < v.size() && ss > v[i].first)
        {
        	ss = max(ss, v[i].second);
        	flag = 0;
            tmp++;
            i++;
        }
        if(flag) i++;
        if(tmp) ans += tmp-1;
    }


    cout<<ans;
}