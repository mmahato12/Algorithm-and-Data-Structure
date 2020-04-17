//https://practice.geeksforgeeks.org/problems/magic-triplets/0
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int a[100005];

int query(int BT[], int i)
{
    int res = 0;
    for( ; i >= 1; i-= i&(-i))
        res += BT[i];
    return res;
}

int update(int BT[], int i, int val)
{
    for( ; i<=n; i+=i&(-i))
        BT[i] += val;
}

void convert()
{
    int temp[n+5];
    for(int i=0; i<n; i++)
        temp[i] = a[i];

    sort(temp, temp+n);

    for(int i=0; i<n; i++)
        a[i] = lower_bound(temp, temp + n, a[i]) - temp + 1;
}

void solve()
{
    int invcount = 0;
    int BT[n+5] = {0};
    int Smaller[n+5] = {0};
    int Greater[n+5] = {0};

    convert();

    for(int i=n-1; i>=0; i--)
    {
        Greater[i] = n-i-1 - query(BT, a[i]);
        update(BT, a[i], 1);
    }

    for(int i=0; i<=n; i++)
        BT[i] = 0;

    for(int i=0; i<n; i++)
    {
        Smaller[i] = query(BT, a[i]-1);
        update(BT, a[i], 1);
    }

    for(int i=0; i<n; i++)
        invcount += Smaller[i] * Greater[i];

    cout<<invcount<<"\n";
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        solve();
    }
}