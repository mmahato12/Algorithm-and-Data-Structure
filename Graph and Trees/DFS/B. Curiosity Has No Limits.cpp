//https://codeforces.com/contest/1072/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
vector<int> v;
int n,a[100005],b[100005],t[100005];

void dfs(int k)
{
//    cout<<v[k-1]<<" ";
    if(v.size()==n)
        return;
    
	for(int i=0; i<=3; i++)
	{
		if((v[k-1]&i)==b[k-1] && (v[k-1]|i)==a[k-1])
		{
			v.push_back(i);
			dfs(k+1);
			return;
		}
	}
}

int32_t main()
{
    int i;
	cin>>n;
	for(i=0; i<n-1; i++)
		cin>>a[i];
	for(i=0; i<n-1; i++)
		cin>>b[i];

	for(i=0; i<=3; i++)
	{
	    v.clear();
		v.push_back(i);
		dfs(1);
		if(v.size()==n)
		{
//		    cout<<i<<"\n";
			break;
		}
	}
	if(i==4){
	    cout<<"NO\n";
	    return 0;
	}
	cout<<"YES\n";
	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<" ";
	cout<<"\n";
}