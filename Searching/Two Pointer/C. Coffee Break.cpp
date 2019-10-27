//https://codeforces.com/contest/1041/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    int n,m,d,a;
    cin>>n>>m>>d;
    int day[n+5] = {0};
    vector < pair <int, int> > v;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back({a, i+1});
    }

    sort(v.begin(), v.end());

    int k = 0;
    int r = 0;
    for(int l=0 ; l<n; l++)
    {
        while(r<n && v[r].first - v[l].first <= d) r++;
        k = max(r-l, k);
    }

    for(int i=0; i<n; i++)
        day[v[i].second] = (i%k) + 1;
    
    cout<<k<<"\n";
    for(int i=1; i<=n; i++)
        cout<<day[i]<<" ";
}