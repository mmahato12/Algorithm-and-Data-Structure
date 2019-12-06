//https://codeforces.com/contest/1260/problem/C
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
        int a,b,k;
        cin>>a>>b>>k;

        if(a > b) swap(a, b);
        
        int x = __gcd(a, b);
        int check = (a+b-x-1)/a;
        
//        cout<<check<<" ";
        
        if(check >= k)
            cout<<"REBEL\n";
        else
            cout<<"OBEY\n";
    }
}