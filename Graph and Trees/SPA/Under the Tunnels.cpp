//https://www.codechef.com/LTIME80B/problems/POPTUNNL
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
    	int n,k;
    	cin>>n>>k;
    	vector <int> v[n+5];
    	for(int i=1; i<=n; i++)
    	{
    		for(int j=1; j<=n; j++)
    		{
    			char c;
    			cin>>c;
    			if(c == '0' || i == j) continue;
    			if(abs(i-j) > k) continue;
    			v[i].push_back(j);
    		}
    	}

    	int ans = 1e18;
    	queue <pair <int, int> > q;
    	int mark[n+5] = {0};
    	q.push({1, 0});
    	mark[1] = 1;

    	while(q.size())
    	{
    		int t = q.front().first;
    		int l = q.front().second;
//    		cout<<t<<" "<<l<<" : ";
    		q.pop();
    		for(auto &x: v[t])
    		{
//    		    cout<<x<<" ";
    			if(mark[x] == 0)
    			{
    				mark[x] = 1;
    				q.push({x, l+1});
    			}
    		}
//    		cout<<"\n";

    		if(t == n)
    			ans = min(l, ans);
    	}
        
        if(ans == 1e18) ans = -1;
    	cout<<ans<<endl;
    }
}
