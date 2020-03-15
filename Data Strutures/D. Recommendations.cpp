//https://codeforces.com/contest/1315/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

priority_queue <pair <int, int> > pq;
map <int, vector <int> > h;
int t[200005];

signed main()
{
    FastIO;
    int n,a;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        h[a].push_back(i);
    }

    for(int i=0; i<n; i++)
        cin>>t[i];
    
    a = 1;
    int ans=0;
    while(true)
    {
        if(pq.empty() && h.find(a) == h.end())
        {
            auto nxt = h.lower_bound(a);
            if(nxt == h.end())
                break;

            a = nxt -> first;
        }
 //     cout<<a<<": ";

        for(auto &x: h[a])
            pq.push({t[x], a});
        
        auto curr = pq.top();
        pq.pop();
        ans += curr.first*(a-curr.second);
        a++;
    }

    cout<<ans;
}