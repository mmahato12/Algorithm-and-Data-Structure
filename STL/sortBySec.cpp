#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define ll long long
#define MAX 2000005

#define ff first
#define ss second
using namespace std;

bool sec(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n,w,tmp,a[105];
    vector < pair<int, int> > v, ans;
    cin>>n>>w;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        v.push_back({i, a[i]});
    }
    
    sort(v.rbegin(), v.rend(), sec);
/*    for(int i=0; i<n; i++)
    {
        cout<<v[i].ff<<" "<<v[i].ss<<"\n"; 
    }*/
    for(int i=0; i<n; i++)
    {
        tmp = (v[i].ss/2) + (v[i].ss%2);
        ans.push_back({v[i].ff, tmp});
        w-= tmp;
        if(w<0)
        {
            cout<<"-1";
            return 0;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        tmp=min(v[i].ss-ans[i].ss, w);
        w-=tmp;
        ans[i].ss+=tmp;
        if(w<0)
        {
            cout<<"-1";
            return 0;
        }
        else if(w==0)
            break;
    }
    sort(ans.begin(), ans.end());
    
//    cout<<"\n----\n";

    if(w>0)
    {
        cout<<"-1";
        return 0;
    }
    
    for(int i=0; i<n; i++)
        cout<<ans[i].ss<<" ";//<<ans[i].ff<<endl; 
}