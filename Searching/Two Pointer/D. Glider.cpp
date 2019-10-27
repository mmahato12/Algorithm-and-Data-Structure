//https://codeforces.com/contest/1041/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    int n,h,a,b;
    cin>>n>>h;
    vector < pair <int, int> > v;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        v.push_back({a, b});
    }
    if(n == 1)
    {
        cout<<v[0].second - v[0].first + h<<"\n";
        return 0;
    }

    sort(v.begin(), v.end());

    int r = 0;
    int curr = 0;
    int maxx = 0, diff = 0;
    for(int l=0 ; l+1<n; l++)
    {
        if(r+1 < n)
            diff = v[r+1].first - v[r].second;
        while(r<n && curr + diff < h)
        {
            curr += diff;
            r++;
            if(r+1 < n)
                diff = v[r+1].first - v[r].second;
            else
                break;
        }
//        cout<<l<<" "<<r<<" : "<<curr<<"\n";
        maxx = max(maxx, v[r].second - v[l].first + (h - curr));
        curr -= v[l+1].first - v[l].second;
    }

    cout<<maxx;
}