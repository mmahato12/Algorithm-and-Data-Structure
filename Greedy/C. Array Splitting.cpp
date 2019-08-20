//https://codeforces.com/contest/1197/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int k;
    int n,a[300005];
    vector <int> v;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i > 0)
            v.push_back(a[i]-a[i-1]);
    }

    int ans = a[n-1] - a[0];
    sort(v.begin(), v.end());

    while(k>1)
    {
        ans = ans - v.back();
        v.pop_back();
        --k;
    }

    cout<<ans;
}