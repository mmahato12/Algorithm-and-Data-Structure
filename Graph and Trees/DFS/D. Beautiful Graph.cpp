//https://codeforces.com/problemset/problem/1093/D

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MOD = 998244353;
vector <int> v[300005];
int mark[300005];
int ans1, ans2;

bool dfs(int u)
{
    if(mark[u] == 0)
        ans1 = (ans1*2)%MOD;
    else
        ans2 = (ans2*2)%MOD;

    for(auto &x: v[u])
    {
        if(mark[x] == -1)
        {
            mark[x] = mark[u] ^ 1;
            if(!dfs(x))
                return false;
        }
        else if(mark[x] == mark[u])
            return false;
    }
    return true;
}

int solve(int u)
{
    ans1 = ans2 = 1;
    mark[u] = 1;
    if(!dfs(u))
        return false;

    return (ans1 + ans2)%MOD;
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0; i<=n; i++)
        {
            v[i].clear();
            mark[i] = -1;
        }

        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        int ans=1;
        for(int i=1; i<=n; i++)
        {
            if(mark[i] == -1)
                ans = (ans * solve(i))%MOD;
        }

        cout<<ans<<"\n";
    }
}