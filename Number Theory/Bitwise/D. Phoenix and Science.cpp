#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n;
    cin>>n;
    vector <int> inc;
    for(int i=1; i<=n; i*=2)
    {
        inc.push_back(i);
        n = n - i;
    }
	
    if(n > 0)
    {
        inc.push_back(n);
        sort(inc.begin(), inc.end());
    }

    cout<<inc.size()-1<<"\n";
    for(int i=1; i<inc.size(); i++)
        cout<<inc[i] - inc[i-1]<<" ";
    cout<<"\n";
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
    cin>>T;
    while(T--)
        solve();
}

//https://codeforces.com/contest/1348/problem/D