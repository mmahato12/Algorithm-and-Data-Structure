//https://codeforces.com/contest/985/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    FastIO;
    int n,k,l;
    cin>>n>>k>>l;
    int a[100005],b[100005],m=n*k;
    for(int i=0; i<m; i++)
    	cin>>a[i];

    sort(a, a+m);

    int up=0;
    for(int i=0; i<m; i++)
    	if(a[i]-a[0]<=l)
    		++up;

	if(up>=n)
	{
		int curr=0,ans=0;
	   	for(int i=0; i<n; i++)
	   	{
	   		ans+=a[curr];
	   		curr=min(curr+k, up-(n-i-1));
	   	}
	   	cout<<ans;
	}
	else
		cout<<"0";

}