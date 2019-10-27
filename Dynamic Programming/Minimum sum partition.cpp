//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0/?track=md-dp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a[n+5],sum=0;
        for(int i=1; i<=n; i++) {
            cin>>a[i];
            sum += a[i];
        }

        bool dp[n+5][sum+5];
        for(int i=0; i<=n; i++)
            for(int j=0; j<=sum; j++)
                dp[i][j] = 0;
                
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(j-a[i] < 0)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = (dp[i-1][j] | dp[i-1][j-a[i]]);
//                cout<<dp[i][j]<<" ";
            }
//            cout<<"\n";
        }

        int ans=0;
        for(int j=0; j<=sum/2; j++)
            if(dp[n][j])
                ans = max(j, ans);
        
        cout<<sum-2*ans<<"\n";
    }
}