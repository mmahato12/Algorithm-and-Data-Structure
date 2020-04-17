//https://codeforces.com/contest/1333/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> find_steps(string s)
{
    int n = s.size();
    vector <int> res;
    for(int i=0; i+1<n; i++)
    {
        if(s[i] == 'R' && s[i+1] == 'L')
        {
            res.push_back(i);
            i++;
        }
    }

    return res;
}

signed main()
{
    FastIO;
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    int cnt=0;
    int mx=0, mn=0, last=-1;
    for(int i=n-1; i>=0; i--)
    {
        if(s[i] == 'L')
            cnt++;
        else
        {
            mx += cnt;
            mn = max(cnt, last+1);
            last = mn;
        }
    }
//    cout<<mn<<" "<<mx<<"\n";

    if(mx < k || mn > k)
    {
        cout<<"-1\n";
        return 0;
    }

    bool is_min = false;
    vector <int> have_steps;
    for(int i=0; i<k; i++)
    {
//        cout<<i<<": ";
        if(!is_min)
        {
            int j = 0;
            auto steps = find_steps(s);
            cout<<min(steps.size()*1ll, mx-k+i+1)<<" ";

            while(k-i-1 < mx && j < steps.size())
            {
                cout<<steps[j]+1<<" ";

                s[steps[j]] = 'L';
                s[steps[j]+1] = 'R';

                mx--;
                j++;
            }

            if(mx == k-i-1)
            {
                is_min = true;
                have_steps = find_steps(s);
            }
        }
        else
        {
            int v = have_steps.back();
            have_steps.pop_back();

            cout<<"1 "<<v+1<<"\n";

            s[v] = 'L';
            s[v+1] = 'R';

            if(v > 0 && s[v-1] == 'R')
                have_steps.push_back(v-1);
            if(v+2 < n && s[v+2] == 'L')
                have_steps.push_back(v+1);
        }
        cout<<"\n";
    }
}
