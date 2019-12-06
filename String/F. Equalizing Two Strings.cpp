//https://codeforces.com/contest/1256/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(string s, int n)
{
    int sum=0;
    for(int c='a'; c<='z'; c++)
    {
        int temp = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] > c)
                temp += 1;
            else if(s[i] == c)
                sum += temp;
        }
    }
//    cout<<sum<<" ";
    return sum;
}

signed main()
{
    FastIO;
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        string s,t;
        bool flag=1,d=0;
        cin>>n>>s>>t;
        int h1[200] = {0};
        int h2[200] = {0};

        for(int i=0; i<n; i++)
        {
            h1[s[i]] += 1;
            h2[t[i]] += 1;
            if(h1[s[i]] > 1) d=1;
        }

        for(int i='a'; i<='z'; i++)
        {
            if(h1[i] != h2[i])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            int a = solve(s, n);
            int b = solve(t, n);

            if(((a+b)%2==0) || d)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
            cout<<"NO\n";
    }
}