//https://codeforces.com/contest/1167/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MAX=1e6+5;
int id[MAX],kk[MAX],vv[MAX],ds[MAX];
vector <int> v[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        x = id[id[x]];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    if(p>q)
        id[p] = id[q];
    else
        id[q] = id[p];
}

signed main()
{
    FastIO;
    int n,m,x,ans=0;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>kk[i];
        for(int j=0; j<kk[i]; j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }

    initialize();
    for(int i=0; i<m; i++)
    {
        sort(v[i].begin(), v[i].end());
        for(int j=0; j<kk[i]; j++)
            union1(v[i][0], v[i][j]);
    }
    
    for(int i=1; i<=n; i++)
    {
        x=root(i);
        ++ds[x];
    }
    
    for(int i=1; i<=n; i++)
    {
        cout<<ds[root(i)]<<" ";
        if(ds[i]>0)
            ++ans;
    }
}