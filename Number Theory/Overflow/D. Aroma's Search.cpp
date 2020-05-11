#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int x0,y0,xs,ys;
    int ax,ay,bx,by,t;
    cin>>x0>>y0>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    
    int LIMIT = (1ll << 62);
    vector <int> x, y;
    x.push_back(x0);
    y.push_back(y0);
    while((LIMIT - bx)/ax >= x.back() && (LIMIT - by)/ay >= y.back())
    {
        x.push_back(x.back()*ax + bx);
        y.push_back(y.back()*ay + by);
    }

    int n = x.size();
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            int len = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            int left = abs(xs - x[i]) + abs(ys - y[i]);
            int right = abs(xs - x[j]) + abs(ys - y[j]);

            if(len <= t - left || len <= t - right)
                ans = max(ans, j-i+1);
        }
    }

    cout<<ans;
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

//https://codeforces.com/contest/1293/problem/D