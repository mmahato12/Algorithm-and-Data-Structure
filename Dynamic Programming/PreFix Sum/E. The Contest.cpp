//https://codeforces.com/contest/1257/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int pref[200005];
int suff[200005];
int where[200005];
int min_suff[200005];

signed main()
{
    FastIO;
    int a,k[3];
    for(int i=0; i<3; i++)
        cin>>k[i];

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<k[i]; j++)
        {
            cin>>a;
            where[a] = i+1;
        }
    }

    int n = k[0]+k[1]+k[2];
    for(int i=1; i<=n; i++)
    {
        pref[0] += (where[i] == 1);
        suff[n+1] += (where[i] == 3);
    }

    for(int i=1; i<=n; i++)
        pref[i] = pref[i-1] - (where[i]==1) + (where[i]==2);
    
    min_suff[n+1] = suff[n+1];
    for(int i=n; i>=1; i--)
    {
        suff[i] = suff[i+1] - (where[i]==3) + (where[i]==2);
        min_suff[i] = min(min_suff[i+1], suff[i]);
    }

    int ans=n+1;
    for(int i=0; i<=n; i++)
    {
        ans = min(ans, min_suff[i+1]+pref[i]);
//        cout<<pref[i]<<" "<<min_suff[i+1]<<"\n";
    }
    
    cout<<ans;
}