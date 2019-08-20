//https://codeforces.com/contest/1178/problem/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MX = 1e6 + 5;
 
int pre[MX], suf[MX];
 
signed main()
{
    FastIO;
    int ans = 0;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(i==0)
            continue;
        if(s[i] == 'v')
        {
            if(s[i-1] == 'v')
                pre[i] = pre[i-1] + 1;
            else
                pre[i] = pre[i-1];
        }
        else
            pre[i] = pre[i-1];
    }
    
    for(int i=s.size()-1; i>=0; i--)
    {
        if(i==s.size()-1)
            continue;
        if(s[i] == 'v')
        {
            if(s[i+1] == 'v')
                suf[i] = suf[i+1] + 1;
            else
                suf[i] = suf[i+1];
        }
        else
            suf[i] = suf[i+1];
    }
 
    for(int i=0; i<s.size(); i++)
    {
//        cout<<pre[i+1]<<" "<<suf[i-1]<<"\n";
        if(s[i] == 'o')
            ans += pre[i+1] * suf[i-1];
    }
 
    cout<<ans;
}