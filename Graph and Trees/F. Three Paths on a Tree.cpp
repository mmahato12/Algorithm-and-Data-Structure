#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> p;
vector <vector <int> > g;

pair <int, int> dfs(int u, int par=-1, int dist=0)
{
    p[u] = par;
    pair <int, int> res = make_pair(dist, u);
    for(auto &x: g[u])
    {
        if(par == x)
            continue;
        res = max(res, dfs(x, u, dist+1));
    }

    return res;
}

void solve()
{
    int n,a,b;
    cin>>n;

    p = vector <int> (n+1);
    g = vector <vector <int> > (n+1);

    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    pair <int, int> da = dfs(1);
    pair <int, int> db = dfs(da.second);

    vector <int> diam;
    a = db.second;
    while(a != da.second)
    {
        diam.push_back(a);
        a = p[a];
    }
    diam.push_back(da.second);

//    cout<<diam.size()<<"\n";
    if(diam.size() == n)
    {
        cout<<n-1<<"\n";
        cout<<diam[0]<<" "<<diam[1]<<" "<<diam.back()<<"\n";
    }
    else
    {
        queue <int> q;
        vector <int> d(n+1, -1);
        for(auto &x: diam)
        {
//            cout<<x<<" ";
            q.push(x);
            d[x] = 0;
        }
//        cout<<"\n";

        while(q.size())
        {
            a = q.front();
            q.pop();
            for(auto &x: g[a])
            {
                if(d[x] == -1)
                {
                    q.push(x);
                    d[x] = d[a] + 1;
                }
            }
        }

        pair <int, int> mx = make_pair(d[1], 1);
        for(int i=1; i<=n; i++){
            mx = max(mx, make_pair(d[i], i));
//            cout<<d[i]<<" "<<i<<" : "<<mx.first<<" "<<mx.second<<"\n";
        }

        cout<<diam.size() + mx.first - 1<<"\n";
        cout<<diam[0]<<" "<<mx.second<<" "<<diam.back()<<"\n";
    }
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

//https://codeforces.com/contest/1294/problem/F