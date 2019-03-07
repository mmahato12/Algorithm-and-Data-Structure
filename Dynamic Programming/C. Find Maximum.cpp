//https://codeforces.com/problemset/problem/353/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
	string s;
	int n,a[100005],pre[100005]={0};
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	cin>>s;

	int ans=0,tmp=0,cur=0;
	pre[0]=a[0];
	for(int i=1; i<n; i++)
		pre[i]=a[i]+pre[i-1];

	for(int i=n-1; i>=0; i--)
	{
		if(s[i]=='1')
		{
			if(i==0) tmp=0;
			else tmp=pre[i-1];

			ans=max(tmp+cur, ans);
			cur+=a[i];
		}
	}

	cout<<max(ans, cur);
}