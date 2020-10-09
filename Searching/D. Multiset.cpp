#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> a, k;

int check(int x)
{
    int cnt = 0;
    for(auto &y: a)
        if(y <= x)
            cnt++;

    for(auto &y: k)
    {
        if(y > 0 && y <= x)
            cnt++;
        if(y < 0 && abs(y) <= cnt)
            cnt--;
    }

    return cnt;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    a.resize(n);
    k.resize(q);
    for(auto &x: a)
        cin>>x;
    for(auto &x: k)
        cin>>x;
        
    if(check(1e9) == 0)
    {
    	cout<<"0";
    	return;
    }

    int lo=0, hi=int(1e6)+1;
    while(hi - lo > 1)
    {
        int mid = (lo + hi)/2;
        if(check(mid) > 0)
            hi = mid;
        else
            lo = mid;
    }

    cout<<hi;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
//    cin>>T;
    while(T--)
        solve();
}

//https://codeforces.com/contest/1354/problem/D