//https://codeforces.com/problemset/problem/1092/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int n;
string a[205];
char ans[205];
vector <string> pos;
map <string, vector<int>> h;

void check(int x)
{
    h.clear();
    multiset <string> s;
    for(int i=0; i<2*n-2; i++)
    {
        s.insert(a[i]);
        h[a[i]].push_back(i);
    }

    string pref = pos[x];
    string suff = pos[x^1];
    while(pref.size())
    {
        if(s.find(pref) != s.end())
        {
            ans[h[pref].back()] = 'P';
            h[pref].pop_back();
            s.erase(s.find(pref));
        }
        else
            break;
        pref.pop_back();
    }
    if(pref.size())
        return;

    while(suff.size())
    {
        if(s.find(suff) != s.end())
        {
            ans[h[suff].back()] = 'S';
            h[suff].pop_back();
            s.erase(s.find(suff));
        }
        else
            return;
        reverse(suff.begin(), suff.end());
        suff.pop_back();
        reverse(suff.begin(), suff.end());
    }
    if(suff.size())
        return;

    for(int i=0; i<2*n-2; i++)
    {
        cout<<ans[i];
    }
    exit(0);
}

signed main()
{
    FastIO;
    cin>>n;
    for(int i=0; i<2*n-2; i++)
    {
        cin>>a[i];
        if(a[i].size() == n-1)
            pos.push_back(a[i]);
    }

    check(0);
    check(1);
}