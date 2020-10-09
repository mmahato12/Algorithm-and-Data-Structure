//https://codeforces.com/contest/1370/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[200005];
int n,k;

bool check(int x, int p)
{
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		if(p&1)
		{
			cnt++;
			p = 1 - p;
		}
		else
		{
			if(x >= a[i])
			{
				cnt++;
				p = 1 - p;
			}
		}
	}

	return cnt >= k;
}

int bsearch(int lo, int hi)
{
	while(lo  < hi)
	{
		int m = (lo + hi)/2;
		if(check(m, 0) || check(m, 1))
			hi = m;
		else
			lo = m+1;
	}

	return lo;
}

void solve()
{
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>a[i];

	int ans = bsearch(1, 1e9);

	cout<<ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
//    cin>>T;
    while(T--)
        solve();
}