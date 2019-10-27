//https://codeforces.com/contest/1106/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> g[100005], ans;
bool mark[100005];

void solve(int u)
{
    priority_queue <int, vector<int>, greater<int>> pq;
    pq.push(u);
    mark[u] = 1;
    while(pq.size())
    {
        int p = pq.top();
        ans.push_back(p);
        pq.pop();
        for(auto &x: g[p])
        {
            if(mark[x] == 0)
            {
                mark[x] = 1;
                pq.push(x);
            }
        }
    }
}

signed main()
{
    FastIO;
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++)
        if(mark[i] == 0)
            solve(i);

    for(auto &x: ans)
        cout<<x<<" ";

}