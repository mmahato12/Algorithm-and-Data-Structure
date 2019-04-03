//https://codeforces.com/problemset/problem/118/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MOD = 1e8;

int dp[105][105][15][15];
int n1,n2,k1,k2;

int dfs(int m1, int m2, int x1, int x2)
{
	if(m1==n1 && m2==n2) return 1;
	if(dp[m1][m2][x1][x2]!=-1) return dp[m1][m2][x1][x2];
	int p=0,q=0;
	if(m1<n1 && x1<k1) p=dfs(m1+1, m2, x1+1, 0);
	if(m2<n2 && x2<k2) q=dfs(m1, m2+1, 0, x2+1);

	return dp[m1][m2][x1][x2]=(p+q)%MOD;
}

int32_t main()
{
    FastIO;
	cin>>n1>>n2>>k1>>k2;
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0, 0, 0, 0);
}