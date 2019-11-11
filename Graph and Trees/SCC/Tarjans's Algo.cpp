#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

stack <int> stk;
vector <int> v[100005];
int disc[100005],low[100005];
bool mark[100005];
int n,m;

int initialize()
{
    for(int i=0; i<n; i++) v[i].clear();
    while(stk.size()){ stk.pop(); }
}

void findComponent(int u)
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    stk.push(u);
    mark[u] = true;
    
    for(auto &x: v[u])
    {
        if(disc[x] == -1)
        {
            findComponent(x);
            low[u] = min(low[u], low[x]);
            //cout<<u<<": "<<low[u]<<"|"<<low[x]<<"\n";
        }
        else if(mark[x])
            low[u] = min(low[u], disc[x]);
    }

    int top = 0;
    if(low[u] == disc[u])
    {
        while(stk.top() != u)
        {
            top = stk.top();
            cout<<top<<" ";
            mark[top] = false;
            stk.pop();
        }
        top = stk.top();
        cout<<top<<"\n";
        mark[top] = false;
        stk.pop();
    }
}

void scc()
{
    for(int i=0; i<n; i++)
    {
        disc[i] = low[i] = -1;
        mark[i] = false;
    }

    for(int i=0; i<n; i++)
        if(disc[i] == -1)
            findComponent(i);
    cout<<"\n";
/*    for(int i=1; i<=n; i++)
        cout<<low[i]<<" "<<disc[i]<<"\n"; */
}

signed main()
{
    FastIO;
    int x,y,T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        initialize();
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            if(x == y) continue;
            v[x].push_back(y);
        }
    
        scc();
    }
}