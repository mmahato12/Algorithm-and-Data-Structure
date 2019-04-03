//https://codeforces.com/contest/1141/problem/F2
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

map <int, vector<pair<int, int> > > sum;
vector <pair<int, int> > best;

bool comp(pair<int, int> a, pair<int,int> b)
{
    if(a.second!=b.second)
        return a.second<b.second;
    else
        return a.first<b.first;
}

int work(vector<pair<int,int> > &v)
{
    sort(v.begin(), v.end(), comp);
    int cur=0,len=0;
    for(auto &it: v)
    {
        if(it.first>cur)
        {
            cur=it.second;
            ++len;
        }
    }
    return len;
}

int32_t main()
{
    FastIO;
    int n;
    cin>>n;
    int a[n+5],ans=0;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
    {
        int s=0;
        for(int j=i; j<=n; j++)
        {
            s+=a[j];
            sum[s].push_back({i, j});
        }
    }

    for(auto &it: sum)
    {
        int cur=work(it.second);
        if(cur>ans)
        {
            ans=cur;
            best=it.second;
        }
    }

    cout<<ans<<"\n";
    int cur=0;
    for(auto &it: best)
    {
        if(it.first>cur)
        {
            cur=it.second;
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
}