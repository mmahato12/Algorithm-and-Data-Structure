//https://codeforces.com/problemset/problem/1081/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MOD = 998244353;
int f[2005][2005];
int n,m,k;

void solve()
{
    cin>>n>>m>>k;
    f[1][0] = m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            (f[i+1][j] += f[i][j])%=MOD;
            (f[i+1][j+1] += f[i][j]*(m-1))%=MOD;
        }
    }
/*    
    for(int i=0; i<=n; i++)
    {
    	for(int j=0; j<=k; j++)
    		cout<<f[i][j]<<" ";
    	cout<<"\n";
    }
    */
    cout<<f[n][k];
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    FastIO;
    int T=1;
//    cin>>T;
    while(T--)
        solve();
}