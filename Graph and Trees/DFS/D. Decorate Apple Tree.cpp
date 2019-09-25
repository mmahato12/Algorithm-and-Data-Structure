//https://codeforces.com/contest/1056/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dis[100005];
vector <int> v[100005];

void dfs(int u)
{
    if(v[u].size() == 0)
    {
        dis[u] = 1;
        return;
    }

    for(auto &x: v[u])
    {
        dfs(x);
        dis[u] += dis[x];
    }
}

signed main()
{
    int n,p;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        cin>>p;
        v[p].push_back(i);
    }

    dfs(1);

    sort(dis+1, dis+n+1);

    for(int i=1; i<=n; i++)
        cout<<dis[i]<<" ";
}