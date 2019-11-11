//https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0/?track=md-dp&batchId=144
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(int a[], int n)
{
    int table[n][n];
    for(int gap = 0; gap < n; gap++)
    {
        for(int i=0, j=gap; j<n; i++, j++)
        {
            int x = (i+2 <= j) ? table[i+2][j] : 0;
            int y = (i+1 <= j-1) ? table[i+1][j-1] : 0;
            int z = (i <= j-2) ? table[i][j-2] : 0;

            table[i][j] = max(a[i] + min(x, y), a[j] + min(y, z));
        }
    }

    return table[0][n-1];
}

signed main()
{
    FastIO;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        int ans = solve(a, n);
        
        cout<<ans<<"\n";
    }
    
}