//https://practice.geeksforgeeks.org/problems/box-stacking/1/?track=md-dp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first
#define ss second

vector < pair <int, pair <int, int> > > box;

bool comp(pair <int, pair <int, int> > aa, pair <int, pair <int, int> > bb)
{
    return ((aa.ss.ff * aa.ss.ss) > (bb.ss.ff * bb.ss.ss));
}

signed main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        box.clear();
        int a,b,c,idx=0;
        int dp[1000]={0};
        for(int i=0; i<n; i++)
        {
            cin>>a>>b>>c;
            box.push_back({0, {0, 0}});
            box.push_back({0, {0, 0}});
            box.push_back({0, {0, 0}});
            
            box[idx].ff = a;
            box[idx].ss.ff = max(b, c);
            box[idx].ss.ss = min(b, c);
            idx++;

            box[idx].ff = b;
            box[idx].ss.ff = max(a, c);
            box[idx].ss.ss = min(a, c);
            idx++;

            box[idx].ff = c;
            box[idx].ss.ff = max(a, b);
            box[idx].ss.ss = min(a, b);
            idx++;
        }

        n = n*3;

        sort(box.begin(), box.end(), comp);
        
        for(int i=0; i<n; i++)
        {
//            cout<<box[i].ss.ff<<" "<<box[i].ss.ss<<" "<<box[i].ff<<"\n";
            dp[i] = box[i].ff;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if((box[i].ss.ff < box[j].ss.ff) && (box[i].ss.ss < box[j].ss.ss))
                    dp[i] = max(dp[j] + box[i].ff, dp[i]);
            }
//            cout<<dp[i]<<" ";
        }

        int ans=0;
        for(int i=0; i<n; i++)
            ans = max(dp[i], ans);

        cout<<ans<<"\n";
    }
}