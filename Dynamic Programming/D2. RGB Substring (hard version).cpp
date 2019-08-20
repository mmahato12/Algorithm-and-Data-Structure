//https://codeforces.com/contest/1196/problem/D2
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int INF=1e18+5;
string t = "RGB";
int dp[200005][3];

bool check(char c, int i, int j)
{
	return t[(i+j)%3] != c;
}

signed main()
{
    FastIO;
	int Q,n,k;
	string s;
	cin>>Q;
	while(Q--)
	{
		cin>>n>>k;
		cin>>s;
		for(int i=0; i<3; i++)
		    for(int j=1; j<=n; j++)
		    	dp[j][i] = dp[j-1][i] + check(s[j-1], i, j-1);

		int ans = INF;
		for(int i=0; i<3; i++)
			for(int j=k; j<=n; j++)
				ans = min(dp[j][i]-dp[j-k][i], ans);

		cout<<ans<<"\n";
	}
}