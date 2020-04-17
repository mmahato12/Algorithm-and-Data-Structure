//https://codeforces.com/contest/1333/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> solve(int n)
{
    vector <int> res(n+1, 0);
    res[0] = 1e18;
    res[1] = 1e18;
    for(int i=2; i<=n; i++)
    {
        if(res[i]) continue;
        for(int j=i; j<=n; j+=i)
        {
            if(res[j]) continue;
            res[j] = j/i;
        }
    }

    return res;
}

signed main()
{
    FastIO;
    int n;
    cin>>n;
    auto v = solve(n);
    sort(v.begin(), v.end());

    for(int i=0; i+1<n; i++)
        cout<<v[i]<<" ";
}