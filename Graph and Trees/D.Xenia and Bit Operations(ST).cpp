//https://codeforces.com/problemset/problem/339/D

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int MOD=1e9+7;
const int N=1e6+5;

int tree[N],arr[N],parity[N];

int build(int idx, int ss, int se)
{
	if(ss==se)
	{
//	    cout<<ss<<" "<<arr[ss]<<"\n";
		tree[idx]=arr[ss];
		parity[idx]=0;
	}
	else
	{
		int mid=(ss+se)/2;
		build(idx*2, ss, mid);
		build(idx*2+1, mid+1, se);
		parity[idx]=1-parity[2*idx];
		
		if(parity[idx])
			tree[idx]=tree[idx*2] | tree[idx*2+1];
		else
			tree[idx]=tree[idx*2] ^ tree[idx*2+1];
//		cout<<ss<<" "<<se<<" "<<tree[idx]<<" "<<tree[idx*2]<<" "<<tree[idx*2+1]<<"\n";
	}
}

int update(int idx, int ss, int se, int x, int val)
{
	if(ss==se)
	{
//	    cout<<ss<<"\n";
		tree[idx]=val;
	}
	else
	{
		int mid=(ss+se)/2;
		if(x<=mid)
			update(2*idx, ss, mid, x, val);
		else
			update(2*idx+1, mid+1, se, x, val);

		if(parity[idx])
			tree[idx]=tree[idx*2] | tree[idx*2+1];
		else
			tree[idx]=tree[idx*2] ^ tree[idx*2+1];
	}
}

int32_t main()
{
	int n,m,l,r;
	cin>>n>>m;
	n=pow(2,n);
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	build(1, 1, n);
/*	for(int i=1; i<2*n; i++)
	    cout<<tree[i]<<" ";
    cout<<"\n";
*/    
	for(int i=0; i<m; i++)
	{
		cin>>l>>r;
		update(1, 1, n, l, r);
/*		for(int i=1; i<2*n; i++)
	        cout<<tree[i]<<" ";
        cout<<"\n";
*/    
		cout<<tree[1]<<"\n";
	}
}