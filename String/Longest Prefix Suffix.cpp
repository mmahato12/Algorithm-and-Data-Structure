//https://practice.geeksforgeeks.org/problems/longest-prefix-suffix/0
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int lps[100005];

void solve(string s, int n)
{
    for(int i=1; i<n; i++)
    {
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j])
            j = lps[j-1];

        if(s[i] == s[j])
            j++;
            
        lps[i] = j;
    }
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        
        solve(s, s.size());
        
        cout<<lps[s.size()-1]<<"\n";
    }
}
