#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int cache[105][105];

int lcs(string s, string t, int n, int m)
{
    if(n == 0 || m == 0)
        return 0;
//    cout<<n<<" "<<m<<" : "<<s[n-1]<<" "<<t[m-1]<<"\n";
    if(cache[n][m] != -1)
        return cache[n][m];

    if(s[n-1] == t[m-1])
        return 1 + lcs(s, t, n-1, m-1);
    else
    {
        int ll = lcs(s, t, n-1, m);
        int rr = lcs(s, t, n, m-1);
        cache[n][m] = max(ll, rr);
        return cache[n][m];
    }
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        string s,t;
        memset(cache, -1, sizeof(cache));
        cin>>n>>m;
        cin>>s>>t;
        cout<<lcs(s, t, n, m)<<"\n";
    }
}
