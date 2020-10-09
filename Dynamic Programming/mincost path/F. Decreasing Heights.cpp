//https://codeforces.com/contest/1353/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int inf = 1e18;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector <vector <int> > a(n, vector <int> (m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];
    
    int ans = inf;
    int a00 = a[0][0];
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<m; y++)
        {
            int need = a[x][y] - x - y;
            if(need > a00)
                continue;
            
            a[0][0] = need;
            vector <vector <int> > dp(n, vector <int> (m, inf));
            dp[0][0] = a00 - need;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    need = a[0][0] + i + j;
                    if(need > a[i][j])
                        continue;

                    if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + a[i][j] - need);
                    if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + a[i][j] - need);
                }
            }
            
            ans = min(ans, dp[n-1][m-1]);
        }
    }

    cout<<ans<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
    cin>>T;
    while(T--)
        solve();
}