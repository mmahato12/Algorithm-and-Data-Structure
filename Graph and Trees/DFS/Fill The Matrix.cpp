//https://www.codechef.com/problems/FILLMTR
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <pair <int, int> > g[100005];
int diff[100005];
int mark[100005];
int ans;

int dfs(int u)
{
    mark[u] = 1;

    for(auto &x : g[u])
    {
        if(mark[x.first] == 0)
        {
            diff[x.first] = diff[u] ^ x.second;
            dfs(x.first);
        }
        else if(mark[x.first] == 1)
        {
            if(diff[u] ^ x.second != diff[x.first])
                ans = 0;
        }
    }

    mark[u] = 2;
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        ans = 1;
        int n,q;
        int a,b,c;
        cin>>n>>q;
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
            mark[i] = 0;
            diff[i] = 0;
        }

        for(int i=0; i<q; i++)
        {
            cin>>a>>b>>c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});

            if(a > b) swap (a, b);
            if(a == b && c)
                ans = 0;
        }

        for(int i=1; i<=n; i++)
        {
            if(mark[i] == 0)
                dfs(i);
        }

        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
}
