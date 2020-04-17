//https://codeforces.com/contest/1335/problem/E2
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        vector <int> a(n);
        for(auto &it: a)
            cin>>it;

        vector <vector <int> > cnt(200, vector <int> (n+1));
        vector <vector <int> > pos(200);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<200; j++)
                cnt[j][i+1] = cnt[j][i];

            ++cnt[a[i] - 1][i+1];
            pos[a[i] - 1].push_back(i);
        }


        int ans = 0;
        for(int i=0; i<200; i++)
        {
            int m = pos[i].size();
            ans = max(ans, m);
            for(int j=0; j<m/2; j++)
            {
                int l = pos[i][j] + 1;
                int r = pos[i][m-j-1] - 1;
                for(int k=0; k<200; k++)
                {
                    int sum = cnt[k][r+1] - cnt[k][l];
                    ans = max(ans, sum + 2*(j+1));
                }
            }
        }

        cout<<ans<<"\n";
    }
}