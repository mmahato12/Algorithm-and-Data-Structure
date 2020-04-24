//https://codeforces.com/contest/1095/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n,ans=0;
    string s;
    cin>>n>>s;
    vector <int> pref(n+1), suff(n+1);
    vector <bool> okp(n+1), oks(n+1);
    okp[0] = oks[n] = true;
    for(int i=0; i<n; i++)
    {
        pref[i+1] = pref[i] + (s[i] == '(' ? +1 : -1);
        suff[n-i-1] = suff[n-i] + (s[n-i-1] == ')' ? +1 : -1);

        okp[i+1] = okp[i] & (pref[i+1] >= 0);
        oks[n-i-1] = oks[n-i] & (suff[n-i-1] >= 0);
    }

    for(int i=0; i<n; i++)
    {
        if(!okp[i] || !oks[i+1])
            continue;
            
        if(s[i] == '(')
        {
            if(pref[i] > 0 && pref[i] - 1 - suff[i+1] == 0)
                ans++;
        }
        else
        {
            if(pref[i] + 1 - suff[i+1] == 0)
                ans++;   
        }
    }

    cout<<ans;
}