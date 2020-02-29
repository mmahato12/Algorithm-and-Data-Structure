//https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> g[1005];
vector<bool> visited(100, false);
vector<int> disc(100, INT_MAX);
vector<int> low(100, INT_MAX);
stack<pair<int, int> > stk;
int odd = 0;
int even = 0;

void dfs(int u, int parent)
{
//    cout<<u<<": "<<parent<<"\n";
    static int tim = 1;
    disc[u] = low[u] = tim++;
    visited[u] = true;
    int child = 0;
    int cnt = 0;
    for(auto &x: g[u])
    {
        if(!visited[x])
        {
//            cout<<u<<":"<<x<<"\n";
            child++;
            stk.push({u, x});
            dfs(x, u);
            low[u] = min(low[u], low[x]);

            if((parent == -1 && child > 1) || (parent!=-1 && low[x] >= disc[u]))
            {
                while(stk.top().first != u && stk.top().second != x)
                {
                    stk.pop();
                    cnt++;
                }
                stk.pop();
                if(cnt&1)
                    odd++;
                else
                    even++;
            }
        }
        else if(x != parent && disc[x] < low[u])
        {
//            cout<<u<<":"<<x<<"\n";
            low[u] = disc[x];
            stk.push({u, x});
        }
    }
}

signed main()
{
    FastIO;
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            int cnt=0;
            dfs(i, -1);
            while(stk.size())
            {
                cnt++;
                stk.pop();
            }

            if(cnt != 0)
            {
                if(cnt&1) odd++;
                else even++;
            }
        }
    }

    cout<<odd<<" "<<even;
}
