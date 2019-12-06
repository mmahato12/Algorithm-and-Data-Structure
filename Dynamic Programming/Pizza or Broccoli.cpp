//https://www.codechef.com/LTIME78A/problems/PIBRO
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T,n,k;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        string a;
        int left[n+5]={0};
        int right[n+5]={0};
        cin>>a;
        for(int i=0; i<n; i++)
        {
            if(a[i] == '1')
                left[i+1] = left[i] + 1;
        }

        for(int i=n; i>=1; i--)
        {
            if(a[i-1] == '1')
                right[i] = right[i+1] + 1;
        }

        int ans=0;
        for(int i=1; i+k-1<=n; i++)
        {
               ans = max(ans, left[i-1]+right[i+k]+k);
//            cout<<left[i]<<" "<<right[i]<<": ";
//            cout<<ans<<"\n";
        }

        cout<<ans<<"\n";
    }
}