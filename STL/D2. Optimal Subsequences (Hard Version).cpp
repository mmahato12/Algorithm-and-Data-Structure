//https://codeforces.com/contest/1262/problem/D2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;

template<typename has_less>
using ordered_set = tree<has_less, null_type, less<has_less>, rb_tree_tag, tree_order_statistics_node_update>;

vector <pair <int, int> > vv,q[200005];

bool comp1(pair <int, int> a, pair <int, int> b)
{
	if(a.first > b.first)
		return true;
	if(a.first == b.first && a.second < b.second)
		return true;
	return false;
}

signed main()
{
    FastIO;
    int n,m;
    cin>>n;
    int a[200005],ans[200005];
    for(int i=1; i<=n; i++)
    {
    	cin>>a[i];
    	vv.push_back({a[i], i});
    }

    sort(vv.begin(), vv.end(), comp1);

    int k,p;
    ordered_set <int> tmp;
    cin>>m;
    for(int i=1; i<=m; i++)
    {
    	cin>>k>>p;
    	q[k].push_back({p, i});
    }

    for(int i=0; i<=n; i++)
    {
    	tmp.insert(vv[i].second);
    	for(auto &x: q[i+1]) {
    	    int xx = *tmp.find_by_order(x.first-1);
	    	ans[x.second] = xx;
    	}
    }

    for(int i=1; i<=m; i++)
    	cout<<a[ans[i]]<<"\n";
}
