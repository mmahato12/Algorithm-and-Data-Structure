//https://codeforces.com/contest/1099/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int ans;
int p[100005];
int s[100005];
vector <int> g[100005];

void nope()
{
    cout<<"-1";
    exit(0);
}

void dfs(int u, int w)
{
//    cout<<u<<" "<<w<<"\n";
    if(s[u] == -1)
    {    
        for(auto &x: g[u])
            if(w > s[x])
                nope();

        s[u] = 1e15;
        for(auto &x: g[u])
            s[u] = min(s[u], s[x]);
        
        if(g[u].size()==0)
            s[u] = w;
    }

    if(s[u] < w)
        nope();

    ans += s[u] - w;
    w = s[u];
    for(auto &x: g[u])
        dfs(x, w);
}

signed main()
{
    FastIO;
    int n;
    cin>>n;
    for(int i=2; i<=n; i++)
    {
        cin>>p[i];
        g[p[i]].push_back(i);
    }

    for(int i=1; i<=n; i++)
        cin>>s[i];

    dfs(1, 0);

    cout<<ans;
}