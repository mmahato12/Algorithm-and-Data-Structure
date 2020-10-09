#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n;
    cin>>n;
    vector <int> v;
    int ans = 1e18;
    for(int i=1; i*i<=n; i++)
    {
    	if(n%i == 0)
    	{
    		int m = (i+(n/i))/2;
    		int x = ((n/i)-i)/2;
//    		cout<<i<<" "<<n/i<<" = "<<m<<" "<<x<<"\n";
    		if(x > 0 && n + x*x == m*m)
		    	ans = min(ans, x*x);
    	}
    }

    if(ans == 1e18) ans = -1;
    cout<<ans<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
    cin>>T;
    while(T--)
        solve();
}

//https://www.codechef.com/LRNDSA05/problems/CHEFSQRS