//https://codeforces.com/contest/1095/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[200005];
int par[200005];

int parent(int x)
{
    if(par[x] == x)
        return x;

    return par[x] = parent(par[x]);
}

void Union(int x, int y)
{
    x = parent(x);
    y = parent(y);

    if(a[x] < a[y])
        par[y] = x;
    else
        par[x] = y;
}

void solve()
{
    int n,m;
    int x,y,w;
    cin>>n>>m;
    int ans= 0, z = 0, mn = 1e18;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        par[i] = i;
        if(a[i] < mn)
        {
            mn = a[i];
            z = i;
        }
    }
    
    vector <pair <int, pair <int, int> > > v;
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y>>w;
        v.push_back({w, {x, y}});
    }

    for(int i=1; i<=n; i++)
        if(z != i)
            v.push_back({a[z] + a[i], {z, i}});

    
    sort(v.begin(), v.end());

    for(auto &itr: v)
    {
        x = itr.second.first;
        y = itr.second.second;
        w = itr.first;

        x = parent(x);
        y = parent(y);
        
        if(x != y)
        {
            ans += w;
            Union(x, y);
        }
    }
    
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