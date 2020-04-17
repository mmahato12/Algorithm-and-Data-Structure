#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int len=0;
        vector <int> v(n),tail(n);
        for(auto &x: v)
            cin>>x;

        tail[len++] = v[0];
        for(int i=1; i<n; i++)
        {
            auto it = lower_bound(tail.begin(), tail.begin()+len, v[i]);
            if(it == tail.begin() + len)
                tail[len++] = v[i];
            else
                *it = v[i];
        }

        cout<<len<<"\n";
    }
}