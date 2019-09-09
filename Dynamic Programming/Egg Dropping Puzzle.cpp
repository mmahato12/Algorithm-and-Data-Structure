//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0/?track=md-dp&batchId=144
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(int n, int k)
{
	int dp[n+5][k+5];
	int res;
	int i,j,x;
	for(int i=1; i<=n; i++)
	{
		dp[i][1] = 1;
		dp[i][0] = 0;
	}

	for(int j=1; j<=k; j++)
		dp[1][j] = j;

	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=k; j++)
		{
			dp[i][j] = INT_MAX;
			for(int x=1; x<=j; x++)
			{
				int res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
				if(res < dp[i][j])
					dp[i][j] = res;
			}
		}
	}

	return dp[n][k];
}

signed main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
    	cin>>n>>k;
        cout<<solve(n, k)<<"\n";
    }
}