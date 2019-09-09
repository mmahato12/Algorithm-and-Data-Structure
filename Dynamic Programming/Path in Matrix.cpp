//https://practice.geeksforgeeks.org/problems/path-in-matrix/0/?track=md-dp&batchId=144
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int ans=0;
	    int a[105][105];
	    int dp[105][105];
	    for(int i=0; i<=100; i++)
	    {
	        for(int j=0; j<=100; j++)
	        {
	            dp[i][j]=0;
	            a[i][j]=0;
	        }
	    }
	    
	    for(int i=1; i<=n; i++)
	        for(int j=1; j<=n; j++)
	            cin>>a[i][j];
	    
	    for(int i=1; i<=n; i++)
	        for(int j=1; j<=n; j++)
	            dp[i][j] = max(dp[i-1][j], max(dp[i-1][j+1], dp[i-1][j-1])) + a[i][j];
	  
	    for(int j=1; j<=n; j++)
	        ans = max(ans, dp[n][j]);
	    
	    cout<<ans<<"\n";
	}
}