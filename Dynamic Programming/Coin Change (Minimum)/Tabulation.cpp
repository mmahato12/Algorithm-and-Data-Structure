#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 2000005
using namespace std;
int c[3]={4,3,1};
int val[105]={},first[105]={};

int main()
{
    FastIO;
	int x;
	cin>>x;
	int n=x;
	for(int i=1; i<=x; i++)
	{
		val[i]=99999999;
		for(int j=0; j<3; j++)
		{
			if(i-c[j]>=0 && val[i-c[j]]+1<val[i])
			{
				val[i]=val[i-c[j]]+1;
				first[i]=c[j];
			}
		}
//		cout<<val[i]<<" ";
	}

	cout<<val[x];
}