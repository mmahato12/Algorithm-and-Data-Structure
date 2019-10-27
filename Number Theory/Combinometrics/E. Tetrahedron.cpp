//https://codeforces.com/problemset/problem/166/E
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int MOD=1e9+7;
int dp[10000005],v=1;

int32_t main()
{
	FastIO;
	int n;
	cin>>n;
	for(int i=2; i<=n; i++)
	{
		v=(v*3+MOD)%MOD;
		dp[i]=(v-dp[i-1]+MOD)%MOD;
	}
	cout<<dp[n];
}