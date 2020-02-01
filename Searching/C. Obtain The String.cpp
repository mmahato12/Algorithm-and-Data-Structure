//https://codeforces.com/contest/1295/problem/C
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
        string s,t;
        cin>>s>>t;
        vector <int> h[505];
        for(int i=0; i<s.size(); i++)
            h[s[i]].push_back(i);

        int i,idx=-1,ans=1;
        for(i=0; i<t.size(); i++)
        {
            if(h[t[i]].size() == 0)
                break;
            
            auto nxt = upper_bound(h[t[i]].begin(), h[t[i]].end(), idx);
            if(nxt == h[t[i]].end())
            {
                ans += 1;
                idx = 0;
            }
            else
                idx = *nxt;
//            cout<<cur<<" ";
        }

        if(i < t.size())
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
    }
}
