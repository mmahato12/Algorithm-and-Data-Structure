//https://codeforces.com/contest/1283/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n;
    map <int, int> h;
    vector <pair <int, int> > ans;    
    cin>>n;
    int a[n+5];
    for(int i=0; i<n-1; i++)
    {
        cin>>a[i];
        h[a[i]] += 1;
    }

    priority_queue <pair <int, int>, vector <pair <int, int> >, greater<pair <int, int> > > pq;
    for(int i=1; i<=n; i++)
        if(h[i] == 0)
            pq.push({i, i});

    for(int i=n-2; i>=0; i--)
    {
        int pp = pq.top().first;
        int lamp = pq.top().second;
        pq.pop();
        
        ans.push_back({lamp, a[i]});
        h[a[i]] -= 1;
        if(h[a[i]] == 0)
            pq.push({max(a[i], pp), a[i]});
    }
    
    cout<<a[0]<<"\n";
    for(auto &x: ans)
        cout<<x.first<<" "<<x.second<<"\n";
}
