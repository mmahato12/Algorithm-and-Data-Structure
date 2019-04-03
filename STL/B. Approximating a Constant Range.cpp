//https://codeforces.com/contest/602/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
	int n,a[100005],ans=0,prev=-1;
	set <int> s;
	map <int, int> h;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];

	for(int i=0; i<n; i++)
	{
		if(s.size()==2 && s.find(a[i])==s.end())
		{
			for (auto x = s.begin(); x != s.end(); x++)
			{
			    auto y=x;
			    auto z=x;
			    z++;
				if((abs(*y-a[i]))>1)
				{
				    prev=h[*y];
					s.erase(y, z);
					break;
				}
			}
		}
		ans=max(i-prev, ans);
		h[a[i]]=i;
		s.insert(a[i]);
	}
	cout<<max(ans, n-prev-1);
}