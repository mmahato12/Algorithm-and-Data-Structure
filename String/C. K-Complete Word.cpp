#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,k,ans;
int cnt[200005][26];
string s;

int calc(int u, int v)
{
    int res = 0, mx = 0;
    for(int j=0; j<26; j++)
    {
        res += cnt[u%k][j] + cnt[v%k][j];
        mx = max(mx, cnt[u%k][j] + cnt[v%k][j]);
    }

//    cout<<u<<" "<<v<<" : "<<res<<" "<<mx<<"\n";
    return res-mx;
}

void solve()
{
    int ans = 0;
    cin>>n>>k>>s;
    for(int i=0; i<k; i++)
        for(int j=0; j<26; j++)
            cnt[i][j] = 0;

    for(int i=0; i<n; i++)
        cnt[i%k][s[i]-'a'] += 1;

    for(int i=0; i<k; i++)
        ans += calc(i, k-i-1);

    cout<<ans/2<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T;
    cin>>T;
    while(T--)
        solve();
}


//https://codeforces.com/contest/1332/problem/C