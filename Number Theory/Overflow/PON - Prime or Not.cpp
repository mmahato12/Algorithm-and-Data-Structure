//https://www.spoj.com/problems/PON/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using u64 = uint64_t;
using u128 = __uint128_t;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while(y > 0)
    {
        if(y&1)
            res = ((u128)res*x)%p;

        y = y>>1;
        x = ((u128)x*x)%p;
    }

    return res;
}

bool millertest(int d, int n)
{
    int a = 2 + rand()%(n-4);
    int x = power(a, d, n);

    if(x == 1 || x == n-1)
        return true;

    while(d != n-1)
    {
        x = ((u128)x*x)%n;
        d *= 2;

        if(x == 1) return false;
        if(x == n-1) return true;
    }

    return false;
}

bool isPrime(int n, int k)
{
    if(n == 2 || n == 3)
        return true;
    if(n <= 4)
        return false;

    int d = n - 1;
    while(d%2 == 0)
        d = d/2;

    for(int i=0; i<k; i++)
        if(!millertest(d, n))
            return false;

    return true;
}

void solve()
{
    int n;
    cin>>n;
    if(isPrime(n, 4))
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
    cin>>T;
    while(T--)
        solve();
}