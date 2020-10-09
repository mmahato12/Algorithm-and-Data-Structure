//https://codeforces.com/contest/1132/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
string s;
int dp[505][505];

int calc(int l, int r)
{
    int &res = dp[l][r];
    if(res != -1)
        return res;

    if(l > r) return 0;
    if(l == r) return 1;

    res = 1 + calc(l+1, r);
//    cout<<"#1 "<<l<<" "<<r<<" : "<<res<<"\n";
    for(int i=l+1; i<=r; i++)
        if(s[l] == s[i])
            res = min(res, calc(l+1, i-1) + calc(i, r));

//    cout<<"#2 "<<l<<" "<<r<<" : "<<res<<"\n\n";
    return res;
}

void solve()
{
    cin>>n>>s;
    memset(dp, -1, sizeof(dp));
    cout<<calc(0, n-1);
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