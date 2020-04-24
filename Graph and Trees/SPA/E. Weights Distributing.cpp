//https://codeforces.com/contest/1343/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 1e18;
vector <vector <int> > g;

void bfs(int a, vector <int> &d)
{
    queue <int> q;
    q.push(a);
    d[a] = 0;
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        for(auto &x: g[a])
        {
            if(d[x] == INF)
            {
                q.push(x);
                d[x] = d[a] + 1;
            }
        }
    }
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,a,b,c;
        cin>>n>>m>>a>>b>>c;
        
        vector <int> p(m);
        for(auto &x: p) cin>>x;
        sort(p.begin(), p.end());
    
        vector <int> pref(m+1);
        for(int i=0; i<m; i++)
            pref[i+1] = pref[i] + p[i];

        int u,v,w;
        g = vector <vector <int> >(n+5);
        for(int i=0; i<m; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> da(n+1, INF), db(n+1, INF), dc(n+1, INF);
        bfs(a, da);
        bfs(b, db);
        bfs(c, dc);

        int ans = INF;
        for(int i=1; i<=n; i++)
        {
            if(da[i] + db[i] + dc[i] > m)
                continue;
            ans = min(ans, pref[db[i]] + pref[da[i] + db[i] + dc[i]]);
        }

        cout<<ans<<"\n";
    }
}