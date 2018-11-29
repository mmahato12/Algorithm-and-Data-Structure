#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
	int T,n,dp[1000005];
	cin>>T;
	dp[1]=1,dp[2]=2;
	for(int i=3; i<71; i++)
	    dp[i]=dp[i-1]+dp[i-2];
	while(T--)
	{
	    cin>>n;
	    cout<<dp[n]<<"\n";
	}
}