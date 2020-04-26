//https://codeforces.com/contest/1207/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,a,b;
        string s;
        cin>>n>>a>>b;
        cin>>s;

        int dp[n+5][2];
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = 1e18;
            dp[i][1] = 1e18;
        }

        dp[0][0] = b;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
            {
                dp[i+1][0] = min(dp[i+1][0], dp[i][0] + a + b);
                dp[i+1][1] = min(dp[i+1][1], dp[i][0] + 2*a + 2*b);

                dp[i+1][0] = min(dp[i+1][0], dp[i][1] + 2*a + b);
                dp[i+1][1] = min(dp[i+1][1], dp[i][1] + a + 2*b);
            }
            else
                dp[i+1][1] = min(dp[i+1][1], dp[i][1] + a + 2*b);
        }

        cout<<dp[n][0]<<"\n";
    }
}
