//https://www.spoj.com/problems/TRT/
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
ll a[1005],best=-1;

ll solve(int y, int f, int r)
{
	if(f>r)
		return 0;
		
	return max(solve(y+1, f+1, r) + y*a[f], solve(y+1, f, r-1) + y*a[r]);
}

int main()
{
    FastIO;
    ll n;
    cin>>n;
    for(int i=0; i<n; i++)
    	cin>>a[i];
    	
    cout<<solve(1, 0, n-1);
}