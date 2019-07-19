//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/robot-in-grid-b7d391f7/description/

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
const int INF=1e17;

int32_t main()
{
	int n,m,Q;
	string s[1005];
	int d[1005][1005];
	cin>>n>>m>>Q;
	for(int i=0; i<n; i++)
	    cin>>s[i];

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			d[i][j]=INF;
	    
	int si,sj;
	cin>>si>>sj;
	si--,sj--;

	queue < pair<int, int> > q;
	q.push({si, sj});
	d[si][sj]=0;
	while(q.size())
	{
		si=q.front().first;
		sj=q.front().second;
		q.pop();
			if(si-1>=0 && s[si-1][sj]=='O' && d[si-1][sj]>d[si][sj]+1)
			{
				d[si-1][sj]=d[si][sj]+1;
				q.push({si-1, sj});
			}
			if(sj-1>=0 && s[si][sj-1]=='O' && d[si][sj-1]>d[si][sj]+1)
			{
				d[si][sj-1]=d[si][sj]+1;
				q.push({si, sj-1});
			}
			if(si+1<n && s[si+1][sj]=='O' && d[si+1][sj]>d[si][sj]+1)
			{
				d[si+1][sj]=d[si][sj]+1;
				q.push({si+1, sj});
			}
			if(sj+1<m && s[si][sj+1]=='O' && d[si][sj+1]>d[si][sj]+1)
			{
				d[si][sj+1]=d[si][sj]+1;
				q.push({si, sj+1});
			}
			
	}

	while(Q--)
	{
		cin>>si>>sj;
		si--;
		sj--;
		if(d[si][sj]==INF)
			cout<<"-1\n";
		else
			cout<<d[si][sj]<<"\n";
	}
}    