//https://codeforces.com/problemset/problem/1138/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector <int> pre(string &s)
{
	int n = s.size();
	vector <int> p(n+5);
	for(int i=1; i<n; i++)
	{
		int j = p[i-1];
		while(j > 0 && s[i] != s[j])
			j = p[j-1];

		if(s[i] == s[j])
			j++;
		p[i] = j;
	}

	return p;
}

int cnt[10];
string s,t,ans;

void solve()
{
	int n;
	vector <int> lps = pre(t);
	int i = 0;
	bool flag = 1;
	while(flag)
	{
		flag = 1;
		while(flag && i < t.size())
		{
			if(cnt[t[i]-'0'] > 0)
			{
				ans += t[i];
				cnt[t[i]-'0']--;
				i++;
			}
			else flag = 0;
		}

		i = lps[i-1];
	}

	while(cnt[0]--) ans += '0';
	while(cnt[1]--) ans += '1';
}

signed main()
{
    FastIO;
    cin>>s>>t;
    for(auto &x: s)
    	cnt[x-'0']++;

    solve();

    cout<<ans;
}