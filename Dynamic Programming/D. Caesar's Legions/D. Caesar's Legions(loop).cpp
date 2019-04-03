#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MOD = 1e8;

int dp[105][105][5];
int n1,n2,k1,k2;

int32_t main()
{
    FastIO;
	cin>>n1>>n2>>k1>>k2;
	for(int i=0; i<=min(n1,k1); i++)
		dp[i][0][0]=1;
	for(int i=0; i<=min(n2,k2); i++)
		dp[0][i][1]=1;

	for(int i=1; i<=n1; i++)
	{
		for(int j=1; j<=n2; j++)
		{
			for(int k=1; k<=min(i, k1); k++)
				dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%MOD;
			for(int k=1; k<=min(j, k2); k++)
				dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%MOD;
		}
	}

	cout<<(dp[n1][n2][0]+dp[n1][n2][1])%MOD;
}