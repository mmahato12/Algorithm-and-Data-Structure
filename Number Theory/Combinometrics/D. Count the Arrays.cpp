//https://codeforces.com/contest/1312/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 998244353;
const int N = 2e5+5;

int fact[N];

int mul(int a, int b)
{
    return (a*b)%MOD;
}

int expo(int a, int b)
{
    int c = 1;
    while(b)
    {
        if(b&1)
            c = mul(c, a);
        a = mul(a, a);
        b = b>>1;
    }
    return c;
}

int inv(int a)
{
    return expo(a, MOD-2);
}

int divide(int a, int b)
{
    return mul(a, inv(b));
}

int C(int n, int r)
{
    return divide(fact[n], mul(fact[r], fact[n-r]));
}

void pre()
{
    fact[0] = 1;
    for(int i=1; i<N; i++)
        fact[i] = mul(fact[i-1], i);
}

signed main()
{
    FastIO;
    pre();
    int n,m;
    cin>>n>>m;
    int ans = 0;
    if(n > 2)
        ans = mul(C(m, n-1), mul(n-2, expo(2, n-3)));

    cout<<ans;
}