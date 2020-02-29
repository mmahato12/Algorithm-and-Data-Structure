//https://codeforces.com/contest/1301/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;

    	int z = n-m;
    	int g = m+1;
    	int k = z/g;
//    	cout<<g<<"="<<k<<" : "<<z%g<<"="<<k+1<<"\n";
    	int ans = (n*(n+1))/2 - ((k*(k+1))/2)*g - (k+1)*(z%g);
    	
    	cout<<ans<<"\n";
    }
}