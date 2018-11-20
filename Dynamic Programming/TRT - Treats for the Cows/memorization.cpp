//https://www.spoj.com/problems/TRT/
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
ll n,a[2005],dp[2005][2005];

ll solve(int f, int r)
{
	if(f>r)
		return 0;
		
	if(dp[f][r]!=-1)
		return dp[f][r];

	int y = n - (r-f+1) + 1;
	dp[f][r] = max(solve(f+1, r) + y*a[f], solve(f, r-1) + y*a[r]);
	
	return dp[f][r];
}

int main()
{
    FastIO;
    cin>>n;
    for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
    	dp[i][j]=-1;
    
    for(int i=0; i<n; i++)
    	cin>>a[i];
    	
    cout<<solve(0, n-1);
}