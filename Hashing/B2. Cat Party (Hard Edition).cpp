//https://codeforces.com/contest/1163/problem/B2
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int maxx;
int f[100005],cnt[100005];

signed main()
{
    FastIO;
    int n,a;
    cin>>n;
    int maxx=0,ans;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        cnt[f[a]]--;
        f[a]++;
        cnt[f[a]]++;
        maxx=max(maxx, f[a]);

        bool ok=false;
        if(cnt[1]==i)
            ok=true;
        else if(f[a]==i)
            ok=true;
        else if(cnt[1]==1 && cnt[maxx]*maxx==i-1)
            ok=true;
        else if(cnt[maxx]==1 && cnt[maxx-1]*(maxx-1)==i-maxx)
            ok=true;

        if(ok)
            ans=i;
    }

    cout<<ans;
}