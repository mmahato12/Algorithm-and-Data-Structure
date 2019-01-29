#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int calc(int n, int k )
{
  //  k=(n+k)/2;
    
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int32_t main()
{
	string s1,s2;
	int n,pos=0,cur=0,uk=0;
	cin>>s1>>s2;
	for(int i=0; i<s1.size(); i++)
		if(s1[i]=='+')
			pos++;
		else
			pos--;

	for(int i=0; i<s2.size(); i++)
		if(s2[i]=='+')
			cur++;
		else if(s2[i]=='-')
			cur--;
		else
			uk++;

	if(abs(pos-cur)<=uk)
	{
		double ans=calc(uk, abs(pos-cur));
		printf("%.9lf\n", ans/pow(2, uk));
	}
	else
		cout<<0;

}
