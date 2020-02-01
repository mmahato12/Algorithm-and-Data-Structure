//https://codeforces.com/contest/1077/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n,a;
    cin>>n;
    vector <int> v;
    map <int, int> h;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        h[a] += 1;
    }

    for(auto &x: h)
        v.push_back(x.second);
        
    sort(v.begin(), v.end());
        
    int ans=0;
    for(int i=1; i<=v.back(); i++)
    {
        int pos = v.size()-1;
        int cur = i;
        int sum = i;
        while(cur%2 == 0 && pos>0)
        {
            pos--;
            cur /= 2;
            if(v[pos] < cur) break;
            sum += cur;
        }

        ans = max(ans, sum);
    }

    cout<<ans;
}
