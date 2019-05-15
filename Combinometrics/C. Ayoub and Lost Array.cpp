//https://codeforces.com/contest/1105/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MOD=1e9+7;
int dp[200005][5];

signed main()
{
    int n,l,r;
    cin>>n>>l>>r;
    int d=(r-l+1)/3;
    dp[1][1]=r/3 + (r%3!=0) - (l-1)/3 - ((l-1)%3!=0);
    dp[1][2]=r/3 + (r%3==2) - (l-1)/3 - ((l-1)%3==2);
    dp[1][3]=r/3 - (l-1)/3;
    for(int i=2; i<=n; i++)
    {
        dp[i][1]=((dp[i-1][2]*dp[1][2])%MOD + (dp[i-1][3]*dp[1][1])%MOD + (dp[i-1][1]*dp[1][3])%MOD)%MOD;
        dp[i][2]=((dp[i-1][1]*dp[1][1])%MOD + (dp[i-1][3]*dp[1][2])%MOD + (dp[i-1][2]*dp[1][3])%MOD)%MOD;
        dp[i][3]=((dp[i-1][3]*dp[1][3])%MOD + (dp[i-1][2]*dp[1][1])%MOD + (dp[i-1][1]*dp[1][2])%MOD)%MOD;
    }
    cout<<dp[n][3];
}