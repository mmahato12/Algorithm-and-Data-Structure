//https://codeforces.com/contest/1342/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n,k;
    cin>>n>>k;
    vector <int> m(n), c(k+5), v[n];
    for(auto &it: m)
        cin>>it;

    sort(m.rbegin(), m.rend());

    for(int i=1; i<=k; i++)
        cin>>c[i];

    int ans = 0;
    for(int i=k,j=0; i>=1; i--)
    {
        while(j < n && m[j] == i)
            j++;
        ans = max(ans, (j+c[i]-1)/c[i]);
    }

    for(int i=0; i<n; i++)
        v[i%ans].push_back(m[i]);

    cout<<ans<<"\n";
    for(int i=0; i<ans; i++)
    {
        cout<<v[i].size()<<" ";
        for(auto &x: v[i])
            cout<<x<<" ";
        cout<<"\n";
    }

}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
//    cin>>T;
    while(T--)
        solve();
}