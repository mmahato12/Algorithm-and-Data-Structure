//https://codeforces.com/contest/1017/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    FastIO;
    int n;
    cin>>n;
    while(A*A < n) A++;
    while(n)
    {
        int x = ((n-1)/A)*A;
        for(int i=x+1; i<n; i++)
            cout<<i<<" ";
        cout<<"\n";
    }
}