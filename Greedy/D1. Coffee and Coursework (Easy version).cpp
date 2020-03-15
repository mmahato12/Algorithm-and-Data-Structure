//https://codeforces.com/contest/1118/problem/D1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i=0; i<n; i++)
    	cin>>a[i];
	
	sort(a, a+n);
	reverse(a, a+n);

    for(int i=1; i<=n; i++)
    {
    	int sum=0;
    	for(int j=0; j<n; j++)
    		sum += max(0ll, a[j] - j/i);

    	if(sum >= m)
    	{
    		cout<<i;
    		return 0;
    	}
    }

    cout<<"-1";
}
