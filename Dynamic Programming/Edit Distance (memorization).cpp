#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int cache[1005][1005];

int solve(string s, string t, int n, int m)
{
    if(n < 0 || m < 0)
        return 1e17;

    if(m==0)
        return n;
    if(n==0)
        return m;
    
    if(cache[n][m] != -1)
        return cache[n][m];

    if(s[n-1] == t[m-1])
        return solve(s, t, n-1, m-1);

    cache[n][m] = 1 + min(solve(s, t, n-1, m-1), min(solve(s, t, n-1, m), solve(s, t, n, m-1)));
    return cache[n][m];
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        memset(cache, -1, sizeof(cache));
        string s,t;
        cin>>n>>m;
        cin>>s>>t;

        cout<<solve(s, t, n, m)<<"\n";
    }
}
