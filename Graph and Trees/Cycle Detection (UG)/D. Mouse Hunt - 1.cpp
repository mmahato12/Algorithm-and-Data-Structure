//https://codeforces.com/contest/1027/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int ans,n;
int c[200005];
int a[200005];
int deg[200005];

void solve()
{
    queue <int> q;
	for(int i=1; i<=n; i++)
    	if(deg[i] == 0)
    		q.push(i);
    
    while(q.size())
    {
    	int tp = q.front();
    	int nxt = a[tp];
    	q.pop();
    	deg[nxt]--;
    	if(deg[nxt] == 0)
    		q.push(nxt);
    }

    for(int i=1; i<=n; i++)
    {
    	if(deg[i] == 0) continue;
    	int u = a[i];
    	int mn = c[i];
    	while(u != i)
    	{
    	    deg[u] = 0;
    		mn = min(mn, c[u]);
    		u = a[u];
    	}

    	ans += mn;
    }
}

signed main()
{
    FastIO;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>c[i];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        deg[a[i]]++;
    }

    solve();

    cout<<ans;
}