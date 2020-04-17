//https://codeforces.com/contest/1326/problem/D2
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int pref[1000005];

string get_palindrome(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    int j = 0;
    for(int i=1; i<a.size(); i++)
    {
        while(j > 0 && a[i] != a[j])
            j = pref[j-1];

        if(a[i] == a[j])
            j++;

        pref[i] = j;
    }
    
    return s.substr(0, j);
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        string s,t;
        cin>>s;
        int l = 0;
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            if(s[i] == s[n-i-1])
                l++;
            else
                break;
        }
        
        if(l > 0)
            cout<<s.substr(0, l);
 
        if(n > 2*l)
        {
            t = s.substr(l, n-2*l);
            string a = get_palindrome(t);
            
            reverse(t.begin(), t.end());
            string b = get_palindrome(t);
            
            if(a.size() < b.size())
                swap(a, b);

            cout<<a;
        }

        if(l > 0)
            cout<<s.substr(n-l, l);

        cout<<"\n";
    }
}