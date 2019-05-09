//https://codeforces.com/problemset/problem/427/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int N=1e5+5;
const int MOD=1e9+7;

vector <int> v[N],todo;
vector <int> g[N],rg[N];
bool vis[N];
int n,cnt,comp[N],a[N];

void dfs1(int u)
{
    vis[u]=true;
    for(auto &x: g[u])
        if(!vis[x])
            dfs1(x);

    todo.push_back(u);
}

void dfs2(int u, int val)
{
//    cout<<u<<" "<<val<<"\n";
    comp[u]=val;
    v[val].push_back(a[u]);
    for(auto &x: rg[u])
        if(comp[x]==-1)
            dfs2(x, val);
}

void scc()
{
    for(int i=1; i<=n; ++i)
        if(!vis[i])
            dfs1(i);

    for(int i=1; i<=n; ++i)
        comp[i]=-1;

    reverse(todo.begin(), todo.end());

    for(auto &x: todo)
    {
//        cout<<x<<": \n";
        if(comp[x]==-1)
        {
            dfs2(x, x);
            ++cnt;
        }
    }
}

int32_t main()
{
    FastIO;
    int m,uu,vv;
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];

    cin>>m;
    while(m--)
    {
        cin>>uu>>vv;
        g[uu].push_back(vv);
        rg[vv].push_back(uu);
    }

    scc();

    int ans1=0,ans2=1;
    for(int i=1; i<=n; ++i)
    {
        if(!v[i].size())
            continue;

        sort(v[i].begin(), v[i].end());

        int c=0,minn=v[i][0];
        ans1+=minn;
        for(auto &x: v[i])
            if(minn==x)
                ++c;

        ans2=(ans2*c)%MOD;
    }

    cout<<ans1<<" "<<ans2;
}