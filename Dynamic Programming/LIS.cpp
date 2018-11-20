#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

int n,arr[105],length[105];

int LIS()
{	
    int maxx=0;
	for(int k=0; k<n; k++)
	{
		length[k]=1;
		for(int i=0; i<k; i++)
			if(arr[i]<arr[k])
				length[k]=max(length[k], length[i]+1);
	}
	for(int k=0; k<n; k++)
	{
//	    cout<<length[k]<<" ";
	    maxx=max(maxx, length[k]);
	}
	return maxx;
}

int main()
{
    FastIO;
    cin>>n;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<LIS();
}