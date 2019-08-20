//https://codeforces.com/contest/1203/problem/D1

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
 
signed main()
{
    FastIO;
    int ans=0;
    string s,t;
    cin>>s>>t;
    for(int i=0; i<s.size(); i++)
    {
    	for(int j=0; j<s.size(); j++)
    	{
    		int pos = 0;
    		for(int p=0; p<s.size(); p++)
    		{
    			if(i <= p && p <= j)
    				continue;
 
    			if(pos < t.size() && t[pos] == s[p])
    				++pos;
    		}
 
    		if(pos == t.size())
    			ans = max(ans, j-i+1);
    	}
    }
 
 
    cout<<ans;
}