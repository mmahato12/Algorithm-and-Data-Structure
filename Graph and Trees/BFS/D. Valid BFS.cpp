//https://codeforces.com/contest/1037/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

set <int> g[200005];
int mark[200005];

signed main()
{
    int n,x,y;
    string ans="Yes";
    cin>>n;
    int a[n+5];
    for(int i=0; i<n-1; i++)
    {
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }

    for(int i=0; i<n; i++)
        cin>>a[i];
    if(a[0] != 1)
    {
        cout<<"No";
        return 0;
    }
    
    int i=1,k;
    queue <int> q;
    q.push(1);
    mark[1] = 1;
    while(q.size())
    {
        int curr = q.front();
        q.pop();
        k = 0;
        for(int j=0; i+j<n && j<g[curr].size(); j++)
        {
            if(g[curr].find(a[i+j]) != g[curr].end())
            {
                if(mark[a[i+j]]==0)
                {
                    mark[a[i+j]] = mark[curr] + 1;
                    q.push(a[i+j]);
                    k++;
                }
            }
        }
        
        for(auto &x: g[curr])
        {
            if(mark[x]==0)
            {
                ans = "No";
                break;
            }
        }
        if(ans=="No") break;
        i += k;
    }

    for(int i=0; i+1<n; i++)
        if(mark[a[i]] > mark[a[i+1]])
            ans = "No";

    cout<<ans;
}