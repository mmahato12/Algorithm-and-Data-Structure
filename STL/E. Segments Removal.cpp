//https://codeforces.com/contest/899/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[200005];
set < pair <int, int> > s, rem;

signed main()
{
    FastIO;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    	cin>>a[i];

    for(int r,l=1; l<=n; l++)
    {
    	r = l;
    	while(r+1 <= n && a[r] == a[r+1])
    		r++;

    	rem.insert({-(r-l+1), l});
    	s.insert({l, r-l+1});

    	l = r;
    }

    int ans = 0;
    while(rem.size())
    {
    	ans++;
    	auto idx = rem.begin()->second;
    	auto it = s.lower_bound({idx, 0});
    	rem.erase(rem.begin());
    	auto L = it, R = it;
    	if(L != s.begin() && R != s.end())
    	{
    		L--;
    		R++;
    		if(R != s.end() && a[L->first] == a[R->first])
    		{
    			rem.erase({-L->second, L->first});
    			rem.erase({-R->second, R->first});

    			rem.insert({-(L->second+R->second), L->first});

    			pair <int, int> cur = make_pair(L->first, L->second+R->second);
    			s.erase(L);
    			s.erase(R);
    			s.insert(cur);
    		}
    	}
    	s.erase(it);
    }

    cout<<ans;
}
