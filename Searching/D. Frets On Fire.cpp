//https://codeforces.com/contest/1119/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int a[100005];
int diff[100005];
int pref[100005];
set <int> s;

signed main()
{
    FastIO;
    int n,q,l,r;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
    	cin>>a[i];
    	s.insert(a[i]);
    }

    sort(a+1, a+n+1);

    for(int i=2; i<=n; i++)
    	diff[i-1] = max(0ll, a[i]-a[i-1]-1);

    sort(diff+1, diff+n);

    for(int i=1; i<=n-1; i++)
    	pref[i] = pref[i-1] + diff[i];

    int initial = s.size();
    cin>>q;
    while(q--)
    {
    	cin>>l>>r;
    	int gap = r-l;

    	int pos = lower_bound(diff+1, diff+n, gap) - diff;
    	int extra = pref[pos-1] + (n-pos)*gap;
    	int ans = extra + initial + gap;
//    	cout<<extra<<" "<<initial<<" "<<gap<<" : ";
    	cout<<ans<<" ";
    }
}