//https://www.codechef.com/LTIME74B/problems/SFRV

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
    	int a[100005], dp[100005] = {0};
    	int n;
    	cin>>n;
    	for(int i=1; i<=n; i++)
    		cin>>a[i];

    	dp[1] = a[1];
    	for(int i=2; i<=n; i++)
    	{
    		dp[i] = max(dp[i-1] + i*a[i], dp[i-2] + a[i]*(i-1) + a[i-1]*i);
    	}

    	cout<<dp[n]<<"\n";
    }
}