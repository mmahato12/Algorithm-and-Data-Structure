//https://codeforces.com/contest/994/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

priority_queue < int, vector<int>, greater<int> > pq;

signed main()
{
    FastIO;
    int n,k;
    cin>>n>>k;
    int p[n+5],c[n+5];
    int coin=0,ans[n+5];
    vector < pair<int, int> > v;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
        v.push_back({p[i], i});
    }

    for(int i=0; i<n; i++)
        cin>>c[i];
    
    sort(v.begin(), v.end());    

    for(int i=0; i<n; i++)
    {
//        cout<<v[i].first<<" "<<v[i].second<<"\n";
        ans[v[i].second] = coin + c[v[i].second];
        if(pq.size() < k)
        {
            coin += c[v[i].second];
            pq.push(c[v[i].second]);
        }
        else if(pq.size() >= max(k, 1ll) && pq.top() < c[v[i].second])
        {
            coin -= pq.top();
            pq.pop();
            coin += c[v[i].second];
            pq.push(c[v[i].second]);
        }
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
}