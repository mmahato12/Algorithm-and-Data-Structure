//https://codeforces.com/contest/1084/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9 + 7;

signed main()
{
    FastIO;
    string s;
    cin>>s;
    int ans=1,cnt=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] != 'a' && s[i] != 'b')
            continue;

        if(s[i] == 'a')
            cnt += 1;
        else if(s[i] == 'b')
        {
            ans = ((ans) * (cnt+1)) % MOD;
            cnt=0;
        }
    }

    if(cnt)
        ans = ((ans) * (cnt+1)) % MOD;
    
    cout<<ans-1;
}