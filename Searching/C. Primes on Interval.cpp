//https://codeforces.com/contest/237/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

const int n=1e6+10;
int a,b,k;
int prime[n];

int check(int l)
{
	for(int i=a; i<=b-l+1; i++)
	{
		int cnt=prime[i+l-1]-prime[i-1];
		if(cnt<k)
			return 0;
	}
	return 1;
}

int bSearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}

	if(check(lo)) return lo;
	else
		return -1;
}

int32_t main()
{
    FastIO;
	cin>>a>>b>>k;
	fill(prime+2, prime+n, 1);
	for(int i=2; i<n; i++)
	{
		if(prime[i])
		{
    		for(int j=2; i*j<n; j++)
	    		prime[i*j]=0;
	    }
	}

	for(int i=2; i<n; i++)
		prime[i]+=prime[i-1];

	int ans=bSearch(1, b-a+1);
	cout<<ans;
}