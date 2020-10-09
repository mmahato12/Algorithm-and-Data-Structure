//https://codeforces.com/contest/1092/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int res, ans;
int sum[200005], a[200005];
vector <int> g[200005];

void dfs(int u, int p=-1, int h=0)
{
    sum[u] = a[u];
    res += h*a[u];
    for(auto &v: g[u])
    {
        if(p == v)
            continue;

        dfs(v, u, h+1);

        sum[u] += sum[v];
    }
}

void calc(int u, int p=-1)
{
    ans = max(ans, res);

    for(auto &v: g[u])
    {
        if(p == v)
            continue;
//        cout<<v<<" = "<<res<<" : "<<sum[u]<<" "<<sum[v]<<"\n";
        res -= sum[v];
        sum[u] -= sum[v];
        res += sum[u];
        sum[v] += sum[u];
//        cout<<v<<" = "<<res<<" : "<<sum[u]<<" "<<sum[v]<<"\n\n";

        calc(v, u);

        res -= sum[u];
        sum[v] -= sum[u];
        res += sum[v];
        sum[u] += sum[v];
    }
}

void solve()
{
    int n,u,v;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n-1; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    calc(1);

    cout<<ans<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
//    cin>>T;
    while(T--)
        solve();
}