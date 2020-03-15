//https://codeforces.com/contest/1325/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int u,v;
    cin>>u>>v;

    if((u%2) != (v%2) || u > v)
    {
        cout<<"-1";
        return 0;
    }

    if(u == v)
    {
        if(!u)
            cout<<"0";
        else
            cout<<"1\n"<<u;
        return 0;
    }

    int x = (v-u)/2;
    if((x^u) == (x|u))
    {
        cout<<"2\n";
        cout<<(x^u)<<" "<<x;
    }
    else
    {
        cout<<"3\n";
        cout<<u<<" "<<x<<" "<<x;
    }
}
