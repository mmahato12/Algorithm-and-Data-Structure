//https://codeforces.com/contest/1064/problem/D

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
 
int dist[2005][2005][2];
 
signed main()
{
    FastIO;
    int n,m, r,c, x,y;
    string s[2005];
    cin>>n>>m;
    cin>>x>>y;
    cin>>r>>c;
    for(int i=0; i<n; i++)
        cin>>s[i];
        
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
        dist[i][j][0]=-1;
        dist[i][j][1]=-1;
    }
    
    priority_queue< pair< pair<int, int>, pair<int, int> >, vector< pair< pair<int, int>, pair<int, int> > >, greater< pair< pair<int, int>, pair<int, int> > > > q;
    q.push({{0, 0}, {x-1, y-1}});
    while(!q.empty())
    {
        auto p = q.top();
        int lx = p.first.first;
        int rx = p.first.second;
        x=p.second.first;
        y=p.second.second;
        q.pop();
        
        if(dist[x][y][0]!=-1)
            continue;
            
        dist[x][y][0]=lx;
	    dist[x][y][1]=rx;
        if(x+1 < n && s[x+1][y]=='.' && dist[x+1][y][0]==-1)
            q.push({{lx, rx}, {x+1, y}});
        if(y+1 < m && s[x][y+1]=='.' && dist[x][y+1][0]==-1)
            q.push({{lx, rx+1}, {x, y+1}});
        if(x > 0 && s[x-1][y]=='.' && dist[x-1][y][0]==-1)
            q.push({{lx, rx}, {x-1, y}});
        if(y > 0 && s[x][y-1]=='.' && dist[x][y-1][0]==-1)
            q.push({{lx+1, rx}, {x, y-1}});
    }
 
    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(dist[i][j][0]!=-1 && dist[i][j][0]<=r && dist[i][j][1]<=c)
                ans++;
 
    cout<<ans;
 
}