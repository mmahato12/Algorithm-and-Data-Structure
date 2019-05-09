//https://codeforces.com/problemset/problem/300/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MOD=1e9+7;
int f[1000005];

int modInverse(int a, int m) 
{
    int m0 = m; 
    int y = 0, x = 1;
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        int q = a / m; 
        int t = m; 
  
        m = a % m, a = t; 
        t = y; 
   
        y = x - q * y; 
        x = t; 
    } 
  
    if (x < 0) 
       x += m0; 
  
    return x; 
}

int32_t main()
{
    FastIO;
    int a,b,n,ans=0;
    cin>>a>>b>>n;

    f[0]=1;
    for(int i=1; i<=n; ++i)
    	f[i]=(f[i-1]*i)%MOD;
    
    for(int i=0; i<=n; ++i)
    {
    	int cnt=1;
		int sum=(i*a)+((n-i)*b);
    	while(sum)
    	{
    		if(sum%10==a || sum%10==b)
    		{
    			sum=sum/10;
    			continue;
    		}
    		cnt=0;
    		break;
    	}
    	if(cnt)
    	{
    		int tmp=((modInverse(f[n-i], MOD))*(modInverse(f[i], MOD)))%MOD;
    		ans=(ans+tmp*f[n])%MOD;
    	}
    }

    cout<<ans%MOD;
}