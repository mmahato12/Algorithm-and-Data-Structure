//https://codeforces.com/contest/1189/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int a;
vector < pair<int, int> > v[70];

signed main()
{
    FastIO;
    int n,q,x,y;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v[0].push_back({a, 0});
    }

    int d=log2(n);
//    cout<<d<<"\n";
    for(int i=0; i<d; i++)
    {
        int p=1<<i;
        for(int j=0; j<v[i].size()-p; j++)
        {
  //          cout<<v[i][j].first<<" ";
            if( v[i][j].first + v[i][j+p].first >= 10)
                v[i+1].push_back({ (v[i][j].first + v[i][j+p].first) % 10, v[i][j].second + v[i][j+p].second + 1});
            else
            v[i+1].push_back({ (v[i][j].first + v[i][j+p].first) % 10, v[i][j].second + v[i][j+p].second});
        }
//        cout<<"\n";
    }
/*    
    for(int i=0; i<=d; i++)
    {
        for(auto &x: v[i])
            cout<<"("<<x.first<<","<<x.second<<") ";
        cout<<"\n";
    }
*/
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        int dd=log2(y-x+1);
        x--;
//        cout<<dd<<" ";
        cout<<v[dd][x].second<<"\n";

    }
}
