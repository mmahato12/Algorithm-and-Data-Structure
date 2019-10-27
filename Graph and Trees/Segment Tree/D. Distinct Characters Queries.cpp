//https://codeforces.com/contest/1234/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int bs[27][400001];
string s;

vector <int> query(int node, int l, int r, int s, int e)
{
    vector <int> v(26, 0);
    if(s > r or l > e)
        return v;
    
    if(l >= s and r <= e)
    {
        for(int i=0; i<26; i++)
            v[i] = bs[i][node];

        return v;
    }

    vector <int> p = query(2*node, l, (l+r)/2, s, e);
    vector <int> q = query(2*node+1, (l+r)/2+1, r, s, e);
    for(int i=0; i<26; i++)
        v[i] = p[i] + q[i];

    return v;
}

void update(int node, int l, int r, int idx, int pos, int sign)
{
    if(idx > r or l > idx) return;

    bs[pos][node] += sign;

    if(l != r) {
        update(2*node, l, (l+r)/2, idx, pos, sign);
        update(2*node+1, (l+r)/2 + 1, r, idx, pos, sign);
    }
}

void build(int node, int l, int r)
{
    if(l == r)
    {
        bs[s[l-1]-'a'][node] = 1;
        return;
    }

    build(2*node, l, (l+r)/2);
    build(2*node+1, (l+r)/2+1, r);

    for(int i=0; i<26; i++)
        bs[i][node] = bs[i][2*node] + bs[i][2*node+1];
}

signed main()
{
    FastIO;
    int q,ans=0;
    cin>>s>>q;

    int n = s.size();
    build(1, 1, n);

    while(q--)
    {
        int type;
        cin>>type;
        if(type == 1)
        {
            char c;
            int pos;
            cin>>pos>>c;
            update(1, 1, n, pos, s[pos-1]-'a', -1);
            s[pos-1] = c;
            update(1, 1, n, pos, c-'a', 1);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            vector <int> res = query(1, 1, n, l, r);
            int ans = 0;
            for(int i=0; i<26; i++)
                if(res[i] > 0)
                    ans++;

            cout<<ans<<"\n";
        }
    }
}