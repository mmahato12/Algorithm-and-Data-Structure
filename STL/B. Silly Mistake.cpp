//https://codeforces.com/contest/1253/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n;
    cin>>n;
    set <int> s,day;
    vector <int> v;
    int a,ans=1,last=-1;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        if(a < 0)
        {
            if(s.count(-a) == 0)
                ans = -1;
            else
            {
                s.erase(-a);
                if(s.size() == 0)
                {
                    v.push_back(i-last);
                    last = i;
                    day.clear();
                }
            }
        }
        else
        {
            if(s.count(a) == 0 && day.count(a) == 0)
            {
                s.insert(a);
                day.insert(a);
            }
            else
                ans = -1;
        }
//        cout<<s.size()<<" ";
    }
    
    if(s.size()) ans = -1;

//    cout<<"\n";
    if(ans == -1)
        cout<<ans<<"\n";
    else
    {
        cout<<v.size()<<"\n";
        for(auto &x: v)
            cout<<x<<" ";
    }
}