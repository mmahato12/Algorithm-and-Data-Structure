#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int dp[1005][1005];

signed main()
{
    FastIO;
    int T,n,W,wt[1005],v[1005];
    cin>>T;
    while(T--)
    {
        cin>>n>>W;
        for(int i=1; i<=n; i++)
            cin>>v[i];
        for(int i=1; i<=n; i++)
            cin>>wt[i];

        for(int i=1; i<=n; i++)
        {
            for(int w=1; w<=W; w++)
            {
                if(wt[i]<=w)
                    dp[i][w]=max(dp[i-1][w], dp[i-1][w-wt[i]] + v[i]);
                else
                dp[i][w] = dp[i-1][w];
            }
        }

        cout<<dp[n][W]<<"\n";
    }
}