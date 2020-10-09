#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n;
    cin>>n;
    int a[n+5];
    int pref[n+5] = {0};
    int suff[n+5] = {0};
    for(int i=1; i<=n; i++)
        cin>>a[i];

    pref[1] = a[1];
    for(int i=2; i<=n; i++)
        pref[i] = __gcd(pref[i-1], a[i]); 

    suff[n] = a[n];
    for(int i=n-1; i>=1; i--)
        suff[i] = __gcd(suff[i+1], a[i]);

    int ans;
    for(int i=1; i<=n; i++)
    {
        if(i == 1)
            ans = suff[i+1];
        else if(i == n)
            ans = (ans*pref[i-1])/__gcd(ans, pref[i-1]);
        else
            ans = (ans*__gcd(pref[i-1], suff[i+1]))/__gcd(ans, __gcd(pref[i-1], suff[i+1]));
    }

    cout<<ans<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
//    cin>>T;
    while(T--)
        solve();
}

//https://codeforces.com/contest/1350/problem/C