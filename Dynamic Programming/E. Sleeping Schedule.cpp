//https://codeforces.com/contest/1324/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 2005;

int n,h,l,r;
int a[N];
int cache[N][N];

int calc(int idx, int cur)
{
    if(idx > n)
        return 0;
    int &ans = cache[idx][cur];
    if(ans != -1)
        return ans;
    ans = 0;
    for(int newT=a[idx]-1; newT<=a[idx]; newT++)
    {
        int tim = (cur+newT)%h;
        int curVal = (l <= tim && tim <= r) + calc(idx+1, tim);
        ans = max(ans, curVal);
    }

    return ans;
}

signed main()
{
    FastIO;
    memset(cache, -1, sizeof(cache));
    cin>>n>>h>>l>>r;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    cout<<calc(1, 0);
}
