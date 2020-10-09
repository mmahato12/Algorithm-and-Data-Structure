#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
int a[105];

int todigit(string s)
{
    int res = 0;
    for(auto &x: s)
        res = res*2 + (x-'0');

    return res;
}

string toString(int x)
{
    int len = 0;
    string res = "";
    while(x > 0)
    {
        if(x%2)
            res = "1" + res;
        else
            res = "0" + res;
        len++;
        x=x/2;
    }

    for(int i=len; i<m; i++)
        res = "0" + res;

    return res;
}

int check(int x)
{
    int rem = (1ll<<m) - n;
    int least = 0;
    if(rem%2)
        least = rem/2;
    else
        least = rem/2 - 1;
    int have = x;
    for(int i=0; i<n; i++)
        have -= (a[i] < x);
    return have >= least;
}

void solve()
{
    string s;
    cin>>n>>m;
    set <int> have;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        a[i] = todigit(s);
        have.insert(a[i]);
    }

    int lo = 0, hi = (1ll<<m)-1;
    while(lo < hi)
    {
        int m = (lo+hi)/2;
        if(check(m))
            hi = m;
        else
            lo = m + 1;
    }

    while(have.find(lo) != have.end())
        lo++;

    cout<<toString(lo)<<"\n";
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