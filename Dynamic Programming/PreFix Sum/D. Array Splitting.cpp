//https://codeforces.com/contest/1175/problem/D
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int suff[300005];
vector <int> suffix;

signed main()
{
    FastIO;
    int T;
    int n,k;
    int a[300005];
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>a[i];
        
    for(int i=n-1; i>=0; i--)
    {
        suff[i]=suff[i+1]+a[i];
//        cout<<suff[i]<<" ";
        if(i>0)
            suffix.push_back(suff[i]);
    }
//    cout<<"\n";

    int best=suff[0];
    sort(suffix.rbegin(), suffix.rend());
    for(int i=0; i<k-1; i++){
//        cout<<suffix[i]<<" ";
        best+=suffix[i];
    }

    cout<<best<<"\n";
}