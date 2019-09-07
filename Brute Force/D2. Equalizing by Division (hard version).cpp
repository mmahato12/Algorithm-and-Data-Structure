#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

vector <int> h(200005, 0);
vector <pair <int, int> > v[200005];

signed main()
{
    FastIO;
    int n,k,a[200005];
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        h[a[i]] += 1;
    }

    for(int i=0; i<2e5+1; i++)
    {
    	int x=i,cnt=0;
    	while(true)
    	{
    		bool check = false;
    		if(x == 0)
    			check = true;
    		v[x].push_back({i, cnt});
    		x = x/2;
    		cnt += 1;

    		if(check)
    			break;
    	}
    }

    int ans = INT_MAX;
    for(int i=0; i<2e5+1; i++)
    {
    	int rem = k, curr=0;
    	for(auto &x: v[i])
    	{
    		int tmp = min(rem, h[x.first]);
    		rem -= tmp;
    		curr += x.second*tmp;
    	}
        
        if(rem == 0)
        {
    	    ans = min(curr, ans);
//            cout<<i<<": "<<curr<<"\n";
        }
    }

    cout<<ans;
}