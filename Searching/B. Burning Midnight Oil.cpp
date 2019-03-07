//https://codeforces.com/problemset/problem/165/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int n,v,k;

bool check(int m)
{
	int res=0,tmp=m,p=1;
	while(tmp)
	{
		res+=tmp;
		tmp=m/pow(k, p);
		p++;
	}
    
//    cout<<m<<" "<<res<<"\n";
	if(res>=n)
		return true;
	else
		return false;
}

int32_t main()
{
	FastIO;
	cin>>n>>k;

	int lo=0,hi=n,ans=n;
	while(lo<=hi)
	{
		int m=(lo+hi)/2;
//		cout<<lo<<" "<<hi<<" : ";
		if(check(m))
		{
			ans=m;
			hi=m-1;
		}
		else
			lo=m+1;
	}

	cout<<ans;
}