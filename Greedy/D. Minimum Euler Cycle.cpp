//https://codeforces.com/contest/1334/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T;
    int cnt=0;
    cin>>T;
    while(T--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        
        int m = 0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1, k=1; j<=n && m+k<=r && l<=m+(n-i)*2; j++)
            {
                if(l <= m + k && m + k <= r)
                    cout<<i<<" ";
                if(l <= m + k + 1 && m + k + 1 <= r)
                    cout<<j<<" ";

                k += 2;
            }

            m += (n-i)*2;
        }
		
		
        if(n*(n-1)+1 <= r)
            cout<<1;
        cout<<"\n";
    }
}