//https://codeforces.com/contest/1118/problem/D2
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
int a[200005];

bool check(int d)
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += max(0ll, a[i] - i/d);

    if(sum >= m)
        return true;
    else
        return false;
}

signed main()
{
    FastIO;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    sort(a, a+n);
    reverse(a, a+n);

    int lo=1, hi=n, ans=-1, t=10;
    while(lo <= hi)
    {
        int m = (lo+hi)/2;
//        cout<<lo<<" "<<hi<<" : "<<m<<"\n";
        if(check(m))
        {
            hi = m-1;
            ans = m;
        }
        else
            lo = m+1;
    }

    cout<<ans;
}
