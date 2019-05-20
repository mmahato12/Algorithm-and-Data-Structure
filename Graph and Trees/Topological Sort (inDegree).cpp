#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int N=20;
int indeg[N];
vector <int> topo
vector <int> g[N];

void topoSort(int n)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=1; i<=n; i++)
        for(auto &x : g[i])
            indeg[x]++;

    for(int i=1; i<=n; i++)
        if(!indeg[i])
            pq.push(i);

    while(pq.size())
    {
        int p=pq.top();
        topo.push_back(p);
        pq.pop();

        for(auto &x: g[p])
        {
            indeg[x]--;
            if(!indeg[x])
                pq.push(x);
        }
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
    }

    topoSort(n);

    for(auto &x: topo)
        cout<<x<<" ";
    
}