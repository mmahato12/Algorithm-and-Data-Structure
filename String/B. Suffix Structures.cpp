//https://codeforces.com/contest/448/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MOD=1e9+7;
const int N=1e6+5;
int hs[27],ht[27],dp[105][105];

int32_t main()
{
    int ans1=0,ans2=0;
    string s,t;
    cin>>s>>t;
    for(int i=0; i<s.size(); i++)
        hs[s[i]-'a']+=1;
    for(int i=0; i<t.size(); i++)
        ht[t[i]-'a']+=1;
        
    for(int i=0; i<26; i++)
    {
        if(ht[i]>hs[i])
        {
            cout<<"need tree";
            return 0;
        }
    }
    
    for(int i=0; i<s.size(); i++)
    {
        int j,k,cnt=0;
        for(int j=0; j<t.size(); j++)
        {
            if(s[i]==t[j])
                dp[i+1][j+1]=max(dp[i][j]+1, max(dp[i+1][j], dp[i][j+1]));
            else
                dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
        }
    }
//    cout<<dp[s.size()][t.size()]<<"\n";
    if(dp[s.size()][t.size()]!=t.size())
        ans2=1;
    
    if(s.size()>t.size())
        ans1=1;

    if(ans1 && ans2)
        cout<<"both";
    else if(ans1)
        cout<<"automaton";
    else if(ans2)
        cout<<"array";

}