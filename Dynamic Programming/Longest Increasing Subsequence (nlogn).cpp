//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int CellIndex(int a[], int l, int r, int key)
{
    while(r - l > 1)
    {
        int m = (r + l)/2;
        if(a[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

signed main()
{
    FastIO;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int len=0;
        int tail[n+5]={0};
        vector <int> v(n);
        for(auto &x: v)
            cin>>x;

        tail[len++] = v[0];
        for(int i=1; i<n; i++)
        {
            if(tail[0] > v[i])
                tail[0] = v[i];
            else if(tail[len-1] < v[i]) 
                tail[len++] = v[i];
            else
                tail[CellIndex(tail, -1, len-1, v[i])] = v[i];
        }

        cout<<len<<"\n";
    }
}
