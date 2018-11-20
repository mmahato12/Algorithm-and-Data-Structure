//https://www.spoj.com/problems/COINS/

#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll c[3]={2,3,4},ans=0;
map <ll, ll> v;

ll solve(ll x)
{
	if(x==0)
		return x;
	if(v[x])
		return v[x];
	
	v[x] = solve(x/2) + solve(x/3) + solve(x/4);
//	cout<<v[x]<<" ";
	
	if(v[x]>x)
		return v[x];
	else
	{
		v[x]=x;
		return x;
	}
}

int main()
{
    FastIO;
    ll n;
    while(cin>>n)
		cout<<solve(n)<<"\n";
}