//https://codeforces.com/contest/329/problem/B

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

queue < pair <int, int> > q;
bool mark[1005][1005];
int dist[1005][1005];
string str[1005];
int r,c;


signed main()
{
    FastIO;
    int sx,sy,x,y,ans=0;
    cin>>r>>c;
    for(int i=0; i<r; i++)
        cin>>str[i];

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(str[i][j]=='T')
                mark[i][j]=true;
            else if(str[i][j]=='E')
                x=i,y=j;
            else if(str[i][j]=='S')
                sx=i,sy=j;
        }
    }

    q.push({x, y});
    mark[x][y]=true;

    while(q.size())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();

        if(x+1<r && mark[x+1][y]==false)
        {
            mark[x+1][y]=true;
            dist[x+1][y]=dist[x][y]+1;
            q.push({x+1,y});
        }
        if(y+1<c && mark[x][y+1]==false)
        {
            mark[x][y+1]=true;
            dist[x][y+1]=dist[x][y]+1;
            q.push({x,y+1});
        }
        if(x-1>=0 && mark[x-1][y]==false)
        {
            mark[x-1][y]=true;
            dist[x-1][y]=dist[x][y]+1;
            q.push({x-1,y});
        }
        if(y-1>=0 && mark[x][y-1]==false)
        {
            mark[x][y-1]=true;
            dist[x][y-1]=dist[x][y]+1;
            q.push({x,y-1});
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(mark[i][j] && str[i][j]>='0' && str[i][j]<='9' && dist[i][j]<=dist[sx][sy])
            {
                ans+=str[i][j]-'0';
            }
        }
    }

    cout<<ans;
}