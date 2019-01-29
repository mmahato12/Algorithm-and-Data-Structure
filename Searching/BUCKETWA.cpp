//https://www.codechef.com/problems/BUCKETWA
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

double dh,dl,dr,k,ans;

double time(double x)
{
    return (sqrt(x*x+dh*dh) + (k*sqrt((dr-x)*(dr-x)+dl*dl)));
}

double dist(double x)
{
    return (sqrt(x*x+dh*dh) + sqrt((dr-x)*(dr-x)+dl*dl));
}

int32_t main()
{
    while(1)
    {
        cin>>dh>>dl>>dr>>k;
        if(dh==0 && dl==0 && dr==0 && k==0)
            break;

        double lo=0,hi=dr;
        while(hi-lo>1e-4)
        {
            double m=(lo+hi)/2.0;
            ans=m;
            if(time(m)>time(m+0.001))
                lo=m;
            else
                hi=m;
        }

        cout<<setprecision(8)<<fixed<<dist(ans)<<"\n";
    }
}