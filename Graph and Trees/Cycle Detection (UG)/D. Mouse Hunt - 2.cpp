//https://codeforces.com/contest/1027/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int ans,idx;
int c[200005];
int a[200005];
int mark[200005];

void solve(int u)
{
    while(1)
    {
        if(mark[u] && mark[u] != idx)
            return;
        if(mark[u] == idx)
            break;
        mark[u] = idx;
        u = a[u];
    }

    int v = a[u];
    int mn = c[u];
    while(u != v)
    {
        mn = min(mn, c[v]);
        v = a[v];
    }

    ans += mn;
}

signed main()
{
    FastIO;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>c[i];
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        idx++;
        solve(i);
    }

    cout<<ans;
}