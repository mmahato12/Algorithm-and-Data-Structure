#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[100005];
int pref[100005],suff[100005];

signed main()
{
    FastIO;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
    	cin>>a[i];
    	if(i == 1) pref[i] = (~a[i]);
    	else pref[i] = pref[i-1]&(~a[i]);
    }
    
    suff[n] = ~a[n];
    for(int i=n-1; i>0; i--)
    	suff[i] = suff[i+1]&(~a[i]);

    int tmp,pos=1,ans=0;
    for(int i=1; i<=n; i++)
    {
//        cout<<pref[i]<<" "<<suff[i]<<" : "<<(a[i]&pref[i-1]&suff[i+1])<<"\n";
        if(i == 1) tmp = a[i]&suff[i+1];
        else if(i == n) tmp = a[i]&pref[i-1];
        else tmp = (a[i]&pref[i-1]&suff[i+1]);
    	if(ans < tmp)
    	{
    		ans = tmp;
    		pos = i;
    	}
    }
    
    cout<<a[pos]<<" ";
    for(int i=1; i<=n; i++)
        if(pos != i)
            cout<<a[i]<<" ";
        
}