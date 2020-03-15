//https://codeforces.com/problemset/problem/1111/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,k,A,B;
vector <int> avengers;

int rec(int l, int r)
{
	int i = lower_bound(avengers.begin(), avengers.end(), l) - avengers.begin();
	int j = upper_bound(avengers.begin(), avengers.end(), r) - avengers.begin();
	j--;
	int x = j-i+1;
	int power_consumed;
	if(x == 0)
		power_consumed = A;
	else
		power_consumed = B*x*(r-l+1);
	
	if(l==r || x==0)
		return power_consumed;

	int m = (l+r)/2;

	return min(power_consumed, rec(l, m)+rec(m+1, r));
}

signed main()
{
    FastIO;
    cin>>n>>k>>A>>B;
	avengers.resize(k);
	for(auto &x: avengers)
		cin>>x;

	sort(avengers.begin(), avengers.end());

	cout<<rec(1, 1ll<<n);
}