//https://codeforces.com/contest/1230/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector < pair<int, int> > Edge;
vector < vector <int> > ways;

void gen(int n, vector <int> v)
{
    if(n == v.size())
    {
        ways.push_back(v);
        return;
    }

    for(int i=1; i<=6; i++)
    {
        v.push_back(i);
        gen(n, v);
        v.pop_back();
    }
}

signed main()
{
    int n,m;
    int x,y,ans=0;
    vector <int> v;
    cin>>n>>m;
    gen(n, v);
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        if(x>y)
            swap(x, y);
        Edge.push_back({x, y});
    }

    for(int i=0; i<ways.size(); i++)
    {
        int cnt=0;
        int dom[10][10]={0};
        for(int j=0; j<m; j++)
        {
            x = Edge[j].first;
            y = Edge[j].second;
            
            --x;
            --y;
            x = ways[i][x];
            y = ways[i][y];
            
            if(dom[x][y] == 0)
            {
                ++cnt;
                dom[x][y] = dom[y][x] = 1;
            }
        }
        ans = max(ans, cnt);
    }

    cout<<ans;
}