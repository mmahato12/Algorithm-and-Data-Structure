//https://codeforces.com/contest/1047/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int N=1.5e7+5;

int a[300005],prime[N],cnt[N];

int32_t main()
{
    FastIO;
    int n,gcd;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i==0) gcd=a[i];
        else gcd=__gcd(a[i], gcd);
    }

    for(int i=0; i<n; i++){
        a[i]=a[i]/gcd;
        cnt[a[i]]+=1;
    }

    if(cnt[1]==n)
    {
        cout<<"-1";
        return 0;
    }

    int ans=n;
    for(int i=2; i<N; i++)
    {
        if(prime[i])
            continue;
        int x=cnt[i];
        for(int j=i+i; j<N; j+=i)
        {
            prime[j]=true;
            x+=cnt[j];
        }
        ans=min(ans, n-x);
    }

    cout<<ans;
}