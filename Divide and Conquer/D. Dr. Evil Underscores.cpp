//https://codeforces.com/contest/1285/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> a;

int solve(vector <int> c, int b)
{
    if(c.size() <= 0 || b < 0)
        return 0;
    
    vector <int> l, r;
    for(auto &x: c)
    {
        if(((x>>b)&1) == 0)
            l.push_back(x);
        else
            r.push_back(x);
    }

    if(l.size() == 0) return solve(r, b-1);
    if(r.size() == 0) return solve(l, b-1);

    return min(solve(l, b-1), solve(r, b-1)) + (1<<b);
}

signed main()
{
    FastIO;
    int n;
    cin>>n;
    a.resize(n);
    for(auto &i: a)
        cin>>i;

    cout<<solve(a, 30);
}
