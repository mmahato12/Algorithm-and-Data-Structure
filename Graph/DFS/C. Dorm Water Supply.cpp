#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define ff first
#define ss second
const int INF=1e17+5;
const int MOD=1e9+7;
const int N=1e6+5;

int p,start,last,mind,visited[1002],d[1002];
vector < pair <int , int> > v;
vector<pair<int,pair<int,int> > > ans;

int dfsy(int u)
{
//    cout<<u<<"-\n";
    for(int i=0; i<p; i++)
    {
//        cout<<visited[i]<<" "<<u<<" "<<v[i].ff<<"-\n";
        if(visited[i]==0 && u==v[i].ff)
        {
            last=v[i].ss;
            mind=min(mind, d[i]);
            visited[i]=1;
            dfsy(v[i].ss);
        }
    }
}
int dfsx(int u)
{
//    cout<<u<<"-\n";
    for(int i=0; i<p; i++)
    {
//        cout<<visited[i]<<" "<<u<<" "<<v[i].ff<<"-\n";
        if(visited[i]==0 && u==v[i].ss)
        {
            start=v[i].ff;
            mind=min(mind, d[i]);
            visited[i]=1;
            dfsx(v[i].ff);
        }
    }
}

int32_t main()
{
    int n,x,y;
    cin>>n>>p;
    for(int i=0; i<p; i++)
    {
        cin>>x>>y>>d[i];
        v.push_back({x-1,y-1});
//        cout<<v[i].ff<<" "<<v[i].ss<<"\n";
    }
//    cout<<"\n";

    for(int i=0; i<p; i++)
    {
        if(visited[i]==0)
        {
//            cout<<i<<"\n";
            start=v[i].ff;
            last=v[i].ss;
            mind=d[i];
            visited[i]=1;
            dfsy(v[i].ss);
//            cout<<start<<" "<<last<<"\n";
            dfsx(v[i].ff);
//            cout<<start<<" "<<last<<"\n";
//            cout<<mind<<"\n";
            if(start==last)
                continue;
            ans.push_back( make_pair( start+1, make_pair( last+1, mind ) ) );
        }
    }
    
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i].ff<<" "<<ans[i].ss.ff<<" "<<ans[i].ss.ss<<"\n";
}