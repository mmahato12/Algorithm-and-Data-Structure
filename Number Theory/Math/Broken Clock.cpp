//https://www.codechef.com/FEB18/problems/BROCLK
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 1e9 + 7;
map <int, int> cache;

int exp(int x, int n)
{
    int res = 1;
    while(n)
    {
        if(n&1)
            res = (res*x)%MOD;

        x = (x*x)%MOD;
        n = n>>1;
    }
    return res;
}

int modular_inverse(int n)
{
    return exp(n, MOD-2);
}

int cos_t_theta(int cos, int t)
{
    if(t == 1)
        return cos;

    auto it = cache.find(t);
    if(it != cache.end())
        return it ->second;

    int temp = cos_t_theta(cos, t/2);

    if(t&1)
        return (cache[t] = (2*temp*cos_t_theta(cos, (t+1)/2) - cos + MOD)%MOD);         //  cos tx = 2 * cos((t-1)/2)x * cos((t+1)/2)x - cos x 
    else
        return (cache[t] = (2*temp*temp - 1 + MOD)%MOD);              // cos tx = 2 * cos(t/2)x * cos(t/2)x - 1 
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int l,d,t;
        cin>>l>>d>>t;
        cache.clear();
        int cos = (d*modular_inverse(l))%MOD;
        int ans = l * cos_t_theta(cos, t)%MOD;
        cout<<ans<<"\n";
    }
}
