//https://www.codechef.com/FEB20A/problems/CHEFRAIL
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(int all[], int p[], int n[])
{
	int res = 0;
	for(int a=1; a*a<=100000; a++)
	{
		for(int b=1; b*b<=100000; b++)
		{
			if(__gcd(a, b) < 2)
			{
				for(int g=1; max(a*a*g, b*b*g)<=100000; g++)
					res += all[a*b*g]*p[a*a*g]*n[b*b*g];
			}
		}
	}
//    cout<<res<<" ";
	return res;
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int a,n,m,zero=0;
        cin>>n>>m;
        int x[100005]={0},y[100005]={0};
        int xp[100005]={0},xn[100005]={0};
        int yp[100005]={0},yn[100005]={0};
        for(int i=0; i<n; i++)
        {
            cin>>a;
            if(a)
                x[abs(a)] += 1;

            if(a > 0)
                xp[abs(a)] += 1;
            else if(a < 0)
                xn[abs(a)] += 1;
            else if(a == 0){
                i--;
                n--;
                zero = 1;
            }
        }

        for(int i=0; i<m; i++)
        {
            cin>>a;
            if(a)
                y[abs(a)] += 1;

            if(a > 0)
                yp[abs(a)] += 1;
            else if(a < 0)
                yn[abs(a)] += 1;
            else if(a == 0) {
                i--;
                m--;
                zero = 1;
            }
        }

        int ans = 0;
        ans += solve(y, xp, xn);
        ans += solve(x, yp, yn);

        if(zero)
            ans += 1ll*n*m;

        cout<<ans<<"\n";
    }
}
