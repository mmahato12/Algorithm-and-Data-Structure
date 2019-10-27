//https://codeforces.com/contest/1113/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int dp[5000000][2];

int32_t main()
{
	FastIO;
	int x,n,cur=0,ans=0;
	cin>>n;
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		cin>>x;
		cur=cur^x;
		if(i>=2)
			ans+=dp[cur][i&1];
		
		dp[cur][i&1]++;
	}

	cout<<ans;
}