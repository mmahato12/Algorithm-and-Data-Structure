//https://codeforces.com/contest/1080/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int cw, cb;

void calc(int x, int y, int n, int m)
{
    cw = 0, cb = 0;
    if((x+y)%2 == 0)
    {
        cw = (n/2 + n%2)*((m+1)/2) + (n/2)*(m/2);
        cb = n*m - cw;
    }
    else
    {
        cb = (n/2 + n%2)*((m+1)/2) + (n/2)*(m/2);
        cw = n*m - cb;
    }
}

void solve()
{
    int n,m;
    int x1,x2,y1,y2;
    int x3,x4,y3,y4;
    cin>>n>>m;
    calc(1, 1, n, m);
    int black = cb;
    int white = cw;
//    cout<<white<<" "<<black<<"\n";

    cin>>y1>>x1>>y2>>x2;
    n = x2 - x1 + 1;
    m = y2 - y1 + 1;
    calc(x1, y1, n, m);
    black -= cb;
    white += cb;
//    cout<<white<<" "<<black<<"\n";

    cin>>y3>>x3>>y4>>x4;
    n = x4 - x3 + 1;
    m = y4 - y3 + 1;
    calc(x3, y3, n, m);
    black += cw;
    white -= cw;
//    cout<<white<<" "<<black<<"\n";

    if(max(x1, x3) <= min(x2, x4) && max(y1, y3) <= min(y2, y4))
    {
//        cout<<"hi\n";
        x3 = max(x1, x3);
        x4 = min(x2, x4);
        y3 = max(y1, y3);
        y4 = min(y2, y4);
        n = x4 - x3 + 1;
        m = y4 - y3 + 1;
        
//        cout<<y3<<" "<<x3<<" "<<y4<<" "<<x4<<"\n";
        calc(x3, y3, n, m);
        black += cb;
        white -= cb;
    }

    cout<<white<<" "<<black<<"\n";
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