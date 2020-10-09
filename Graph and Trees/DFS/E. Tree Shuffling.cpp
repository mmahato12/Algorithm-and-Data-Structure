#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 2e5 + 5;
vector <int> g[N];
int cost[N], b[N], c[N];
int n, ans;

pair <int, int> dfs(int u, int p, int mn)
{
    pair <int, int> a = {0, 0};
    if(b[u] != c[u])
    {
        if(b[u])
            a.first++;
        else
            a.second++;
    }

    for(auto &x: g[u])
    {
        if(x == p)
            continue;

        pair <int, int> pp = dfs(x, u, min(cost[u], mn));
        a.first += pp.first;
        a.second += pp.second;
    }

    if(cost[u] < mn)
    {
        int take = min(a.first, a.second);
        ans += 2*take*cost[u];
        a.first -= take;
        a.second -= take;
    }

    return a;
}

void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>cost[i]>>b[i]>>c[i];

    int x, y;
    for(int i=1; i<n; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    pair <int, int> a = dfs(1, 0, 1e12);

    if(a.first || a.second)
        cout<<"-1";
    else
        cout<<ans;
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

//https://codeforces.com/contest/1363/problem/E