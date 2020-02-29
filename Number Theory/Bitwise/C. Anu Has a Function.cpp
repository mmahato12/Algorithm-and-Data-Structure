//https://codeforces.com/contest/1300/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[100005][33], sum[33];

signed main()
{
    FastIO;
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
    	cin>>a[i];
    	for(int j=0; j<33; j++)
    	{
    		if(a[i] & (1ll<<j))
    		{
    			dp[i][j]++;
    			sum[j]++;
    		}
    	}
    }

    int pos = 0, mx = 0;
    for(int i=0; i<n; i++)
    {
    	int tmp=0;
    	for(int j=0; j<33; j++)
    	{
    		if(sum[j] == 1 && dp[i][j] == 1)
    			tmp = (1ll<<j);
    	}
        
//        cout<<tmp<<" ";
    	if(mx < tmp)
    	{
    		mx = tmp;
    		pos = i;
    	}
    }
//    cout<<"\n";
    
//    cout<<mx<<"\n";
    cout<<a[pos]<<" ";
    for(int i=0; i<n; i++)
    	if(i != pos)
	    	cout<<a[i]<<" ";
}