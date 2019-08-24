//https://codeforces.com/contest/1204/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int n,m;
    cin>>n;
    string s;
    int dist[n][n];
    for(int i=0; i<n; i++)
    {
    	cin>>s;
    	for(int j=0; j<n; j++)
    	{
    		if(s[j] == '1')
    			dist[i][j] = 1;
    		else
    			dist[i][j] = 1e9;

    		if(i == j)
    			dist[i][j] = 0;
    	}
    }

	cin>>m;
	int p[m];
    for(int i=0; i<m; i++)
    	cin>>p[i];

    for(int k=0; k<n; k++)
    	for(int i=0; i<n; i++)
    		for(int j=0; j<n; j++)
    			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    vector <int> v;
    v.push_back(0);
    for(int i=1; i<m; i++)
    {
    	if(dist[p[v.back()]-1][p[i]-1] < i - v.back())
    		v.push_back(i-1);
    }
    v.push_back(m-1);

    cout<<v.size()<<"\n";
    for(auto &x: v)
    	cout<<p[x]<<" ";
}