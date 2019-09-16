//https://codeforces.com/contest/1036/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    int q,x,y,k;
    cin>>q;
    while(q--)
    {
        cin>>x>>y>>k;
        if(x < y) swap(x, y);
        if((x%2) != (y%2))
        {
            x--;
            k--;
        }
        else if((x%2) != (k%2))
        {
            x--;
            y--;
            k-=2;
        }

        if(k < x)
            cout<<"-1\n";
        else
            cout<<k<<"\n";
    }
}