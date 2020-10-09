//https://codeforces.com/contest/1288/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
int a[300005][10];
int ans1, ans2;

bool can(int mn)
{
    vector <int> mask(1<<m, -1);
    for(int i=0; i<n; i++)
    {
        int cur = 0;
        for(int j=0; j<m; j++)
            if(mn <= a[i][j])
                cur += (1<<j);
        mask[cur] = i;
    }

    if(mask[(1<<m)-1] != -1)
    {
        ans1 = ans2 = mask[(1<<m)-1];
        return true;
    }

    for(int i=0; i<(1<<m); i++)
    {
        for(int j=0; j<(1<<m); j++)
        {
            if(mask[i] != -1 && mask[j] != -1 && (i|j) == (1<<m)-1)
            {
                ans1 = mask[i];
                ans2 = mask[j];
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>a[i][j];

    int lo = 0, hi = 1e9+5;
    while(hi - lo > 1)
    {
        int mi = (lo+hi)/2;
//        cout<<lo<<" "<<hi<<" : "<<mi<<"\n";
        if(can(mi))
            lo = mi;
        else
            hi = mi;
    }

//    cout<<lo<<"\n";
    cout<<ans1+1<<" "<<ans2+1<<"\n";
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