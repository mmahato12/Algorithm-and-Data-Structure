//https://www.hackerearth.com/practice/algorithms/graphs/flood-fill-algorithm/tutorial/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int visited[15][15];

void DFS(int x, int y, int n, int m)
{
    if (x >= n || y >= m)
        return;
    if(x < 0 || y < 0)
        return;
    if(visited[x][y] == 0)
        return;
    if(visited[x][y] == 2)
        return;

    visited[x][y] = 2;
//    DFS(x-1, y-1, n, m);
    DFS(x-1, y, n, m);
//    DFS(x-1, y+1, n, m);
    DFS(x, y-1, n, m);
    DFS(x, y+1, n, m);
//    DFS(x+1, y-1, n, m);
    DFS(x+1, y, n, m);
//    DFS(x+1, y+1, n, m);
}

signed main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>visited[i][j];

    DFS(0, 0, n, m);

    if(visited[n-1][m-1] == 2)
        cout<<"Yes";
    else
        cout<<"No";
}