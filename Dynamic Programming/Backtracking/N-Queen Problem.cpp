#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
bool board[15][15];
vector <int> v;
vector <vector <int> > vv;

bool isSafe(int row, int col)
{
    for(int i=0; i<col; i++)
        if(board[row][i])
            return false;

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return false;

    for(int i=row, j=col; i<n && j>=0; i++, j--)
        if(board[i][j])
            return false;

    return true;
}

void solve(int col)
{
    if(col >= n)
    {
        vv.push_back(v);
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(isSafe(i, col))
        {
            board[i][col] = 1;
            v.push_back(i);

            solve(col+1);

            board[i][col] = 0;
            v.pop_back();
        }
    }
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        vv.clear();
        v.clear();
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                board[i][j] = 0;

        solve(0);
        
        if(vv.size())
        {
            for(int i=0; i<vv.size(); i++)
            {
                cout<<"[";
                for(int j=0; j<vv[i].size(); j++)
                    cout<<vv[i][j]+1<<" ";
                cout<<"] ";
            }
            cout<<"\n";
        }
        else
            cout<<"-1\n";
    }
}