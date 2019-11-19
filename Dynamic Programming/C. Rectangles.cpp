//https://codeforces.com/problemset/problem/1028/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int INF = 1e15;

signed main()
{
    FastIO;
    int n;
    cin>>n;
    int a[n+5][5];
    int a[n+5][5];
    int a[n+5][5];
    for(int i=0; i<n; i++)
        for(int j=0; j<4; j++)
            cin>>a[i][j];

    b[0][0] = b[0][1] = c[n][0] = c[n][1] = -INF;
    b[0][2] = b[0][3] = c[n][2] = c[n][3] = INF;
    for(int i=0; i<n; i++)
    {
        b[i+1][0] = max(b[i][0], a[i][0]);
        b[i+1][1] = max(b[i][1], a[i][1]);
        b[i+1][2] = min(b[i][2], a[i][2]);
        b[i+1][3] = min(b[i][3], a[i][3]);
    }

    for(int i=n-1; i>=0; i++)
    {
        c[i][0] = max(c[i+1][0], a[i][0]);
        c[i][1] = max(c[i+1][1], a[i][1]);
        c[i][2] = min(c[i+1][2], a[i][2]);
        c[i][3] = min(c[i+1][3], a[i][3]);
    }

    int x1,x2,y1,y2;
    for(int i=0; i<n; i++)
    {
        x1 = max(b[i][0], c[i][0]);
        y1 = max(b[i][0], c[i][0]);
        x2 = min(b[i][0], c[i][0]);
        y2 = min(b[i][0], c[i][0]);

        if(x1 <= x2 && y1 <= y2)
        {
            cout<<x1<<" "<<x2<<"\n";
            break;
        }
    }
}