//https://codeforces.com/problemset/problem/1033/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int ans[100005];
int a[100005],p[100005];
signed main()
{
    FastIO;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        p[a[i]] = i;
        if(a[i] == n)
            ans[i] = 1;
    }

    for(int i=n-1; i>=1; i--)
    {
        int s = p[i]%i;
//        cout<<i<<" "<<p[i]<<" : ";
        bool check = 1;
        for(int j=s; j<=n; j+=i)
        {
            if(a[j] < i) continue;
            if(ans[j])
            {
                check = 0;
                break;
            }
        }
//        cout<<char('A'+check)<<"\n";
        if(check)
            ans[p[i]] = 1;
    }

    for(int i=1; i<=n; i++)
        cout<<char('A'+ans[i]);
}