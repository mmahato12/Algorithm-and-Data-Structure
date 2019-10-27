//https://codeforces.com/contest/1106/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> ans;
vector <pair<int, int> > v,Copy;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if(a.first > b.first)
        return true;
    if(a.first == b.first && a.second > b.second)
        return true;
    return false;
}

signed main()
{
    FastIO;
    int n,m;
    int t,d;
    cin>>n>>m;
    int a[n+5],c[n+5];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
    {
        cin>>c[i];
        v.push_back({c[i], i});
    }

    sort(v.begin(), v.end(), comp);
    
    int cost, take;
    for(int i=0; i<m; i++)
    {
        cin>>t>>d;
        take = min(a[t-1], d);
        cost = take*c[t-1];
        d = d - take;
        a[t-1] = a[t-1] - take;
        for(int j=n-1; j>=0 && d>0; j--)
        {
            take = min(a[v[j].second], d);
            if(take)
                Copy.push_back({v[j].second, a[v[j].second]});
            cost += take*v[j].first;
            d = d - take;
            a[v[j].second] = a[v[j].second] - take;
        }
        while(v.size() && a[v.back().second] == 0)
            v.pop_back();
        n = v.size();
        if(d)
        {
            for(auto &x: Copy)
                a[x.first] = x.second;
            ans.push_back(0);
        }
        else
            ans.push_back(cost);
        Copy.clear();
    }

    for(auto &x: ans)
        cout<<x<<"\n";
}