#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD=1e9+7;

signed main()
{
	int T,n,dp[105];
	for(int i=1; i<=100; i++)
	{
	    if(i<=2)
	        dp[i]=i;
	    else
	    dp[i]=(dp[i-1]+((i-1)*dp[i-2])%MOD)%MOD;
	}
	
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    cout<<dp[n]<<"\n";
	}
}