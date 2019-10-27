//https://codeforces.com/contest/1058/problem/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    FastIO;
    int n,m,k,x,y,g;
    cin>>n>>m>>k;
    int area=(2*n*m);
    if(area%k)
        cout<<"NO";
    else
    {
        if(k%2)
        {
            g=__gcd(k, n);
            k=k/g;
            x=n/g;
            y=m/k;
            if(2*x<=n)
                x*=2;
            else
                y*=2;
        }
        else
        {
            k=k/2;
            g=__gcd(k, n);
            k=k/g;
            x=n/g;
            y=m/k;
        }

        cout<<"YES\n";
        cout<<"0 0\n";
        cout<<x<<" "<<0<<"\n";
        cout<<0<<" "<<y<<"\n";
    }
}