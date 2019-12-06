//https://www.codechef.com/NOV19A/problems/WEIRDO
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
typedef long double ld;
const int MAXN = 1e5 + 10;

int n,sz[2];
string s[2][MAXN];
int cnt[2][26];

bool check(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    return false;
}

bool belongsToAlice(string t)
{
    int last = -1;
    for(int i=0; i<t.size(); i++)
    {
        if(!check(t[i]))
        {
            if(last != -1 && i-last < 3)
                return false;
            last = i;
        }
    }
    return true;
}

signed main()
{
    FastIO;
    int T;
    cout << fixed << setprecision(12);
    cin>>T;
    while(T--)
    {
        string t;
        cin>>n;
        sz[0] = sz[1] = 0;
        for(int i=0; i<n; i++)
        {
            cin>>t;
            if(belongsToAlice(t))
                s[0][sz[0]++] = t;
            else
                s[1][sz[1]++] = t;
        }

        ld prod[2] = {.0, .0};
        for(int w=0; w<2; w++)
        {
            memset(cnt, 0, sizeof(cnt));
            for(int i=0; i<sz[w]; i++)
            {
                int mask=0;
                for(char ch: s[w][i])
                {
                    int x = ch-'a';
                    cnt[1][x]++;
                    if(!(mask>>x&1))
                    {
                        cnt[0][x]++;
                        mask |= 1<<x;
                    }
                }
            }

            for(int i=0; i<26; i++)
                if(cnt[1][i])
                    prod[w] += log(ld(cnt[0][i])) - log(cnt[1][i])*sz[w];
        }
        
        ld ans = prod[0] - prod[1];
        ans = exp(ans);
        if(ans > 1e7)
            cout<<"Infinity\n";
        else
            cout<<ans<<"\n";
    }

    return 0;
}