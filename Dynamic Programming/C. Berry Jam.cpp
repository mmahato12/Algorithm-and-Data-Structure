//https://codeforces.com/contest/1278/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        int n,ans=0;
        cin>>n;
        int a[2*n+5],p[2*n+5],s[2*n+5];
        p[0] = 0;
        for(int i=1; i<=2*n; i++)
        {
            cin>>a[i];
            p[i] = p[i-1] + (a[i] == 1 ? 1 : -1);
        }
        
        s[2*n+1] = 0;
        map <int, int> pos = {{0, 0}};
        for(int i=2*n; i>=n+1; i--)
        {
            s[i] = s[i+1] + (a[i] == 1 ? -1 : 1);
            pos[s[i]] = 2*n + 1 - i;
        }

        for(int i=0; i<=n; i++)
        {
            if (pos.count(p[i]))
                ans = max(ans, i + pos[p[i]]);
        }

        cout<<2*n - ans<<"\n";
    }
}