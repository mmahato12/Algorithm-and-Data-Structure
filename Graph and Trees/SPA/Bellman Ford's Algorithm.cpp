#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MAXX=1e6+5;
vector <int> v [MAXX];
int dis [MAXX];

signed main()
{
    FastIO;
    for(int i=0; i<MAXX; i++)
        dis[i]=1e18;
    
    int n,m;
    int from,next,weight;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>from>>next>>weight;
        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight);
    }
    
    dis[1]=0;
    for(int i=0; i<n-1; i++)
    {
        int j=0;
        while(v[j].size())
        {
            if(dis[v[j][0]] + v[j][2] < dis[v[j][1]])
                dis[v[j][1]] = dis[v[j][0]] + v[j][2];
            ++j;
        }
    }

    for(int i=2; i<=n; i++)
        cout<<dis[i]<<" ";
}
