//https://codeforces.com/contest/1138/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int a[1005][1005];
vector <int> vc[1005],vr[1005];

int32_t main()
{
    FastIO;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
            vr[i].push_back(a[i][j]);
            vc[j].push_back(a[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        sort(vr[i].begin(), vr[i].end());
        vr[i].resize(unique(vr[i].begin(), vr[i].end()) - vr[i].begin());
    }
    
    for(int j=0; j<m; j++){
        sort(vc[j].begin(), vc[j].end());
        vc[j].resize(unique(vc[j].begin(), vc[j].end()) - vc[j].begin());
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int rank_R=lower_bound(vr[i].begin(), vr[i].end(), a[i][j]) - vr[i].begin();
            int rank_C=lower_bound(vc[j].begin(), vc[j].end(), a[i][j]) - vc[j].begin();
            int r_size=vr[i].size();
            int c_size=vc[j].size();
            a[i][j]=max(rank_C, rank_R)+max(r_size-rank_R, c_size-rank_C);
            cout<<a[i][j]<<" ";
        }
        
        cout<<"\n";
    }
}