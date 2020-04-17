//https://codeforces.com/contest/1337/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int sz[5];
set <int> store[5];

int great(int idx, int x)
{
    auto it = store[idx].lower_bound(x);
    if(it == store[idx].end())
        return -1;
    return *it;
}

int lesser(int idx, int x)
{
    auto it = store[idx].lower_bound(x);
    if(it == store[idx].begin())
        return -1;
    it--;
    return *it;
}

int sum(int a, int b, int c)
{
    return (a-b)*(a-b) + (a-c)*(a-c) + (c-b)*(c-b);
}

signed main()
{
    FastIO;
    int T,x;
    cin>>T;
    while(T--)
    {
        int ans = LLONG_MAX;
        for(int i=1; i<=3; i++)
        {
            store[i].clear();
            cin>>sz[i];
        }

        for(int i=1; i<=3; i++)
        {
            for(int j=0; j<sz[i]; j++)
            {
                cin>>x;
                store[i].insert(x);
            }
        }

        for(auto &it: store[1])
        {
            int a = it;
            {
                int b = lesser(2, a);
                int c = lesser(3, a);
                if(b > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int b = lesser(2, a);
                int c = great(3, a);
                if(b > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int b = great(2, a);
                int c = lesser(3, a);
                if(b > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int b = great(2, a);
                int c = great(3, a);
                if(b > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
        }

        for(auto &it: store[2])
        {
            int b = it;
            {
                int a = lesser(1, b);
                int c = lesser(3, b);
                if(a > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int a = lesser(1, b);
                int c = great(3, b);
                if(a > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int a = great(1, b);
                int c = lesser(3, b);
                if(a > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int a = great(1, b);
                int c = great(3, b);
                if(a > 0 && c > 0)
                    ans = min(ans, sum(a, b, c));
            }
        }

        for(auto &it: store[3])
        {
            int c = it;
            {
                int a = lesser(1, c);
                int b = lesser(2, c);
                if(a > 0 && b > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int a = lesser(1, c);
                int b = great(2, c);
                if(a > 0 && b > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int a = great(1, c);
                int b = lesser(2, c);
                if(a > 0 && b > 0)
                    ans = min(ans, sum(a, b, c));
            }
            {
                int a = great(1, c);
                int b = great(2, c);
                if(a > 0 && b > 0)
                    ans = min(ans, sum(a, b, c));
            }
        }

        cout<<ans<<"\n";
    }
}