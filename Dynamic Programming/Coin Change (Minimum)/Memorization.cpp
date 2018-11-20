#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 2000005
using namespace std;
int c[3]={4,3,1};
int val[105]={};

int solve(int x)
{
	if(x<0)
		return 999999999;
	if(x==0)
		return 0;
	if(val[x])
		return val[x];

	int best=999999999;
		
	for(int i=0; i<3; i++)
		best=min(best, solve(x-c[i])+1);

//	cout<<best<<" ";
	val[x]=best;
	return best;
}

int main()
{
    FastIO;
	int x;
	cin>>x;
	cout<<solve(x);
}