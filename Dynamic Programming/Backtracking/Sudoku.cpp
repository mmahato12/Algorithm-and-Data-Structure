#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define EMPTY 0

int grid[10][10];

bool UsedInBox(int row, int col, int num)
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(grid[row+i][col+j] == num)
                return false;
    return true;
}

bool UsedInRow(int row, int num)
{
    for(int i=0; i<9; i++)
        if(grid[row][i] == num)
            return false;
    return true;
}

bool UsedInCol(int col, int num)
{
    for(int i=0; i<9; i++)
        if(grid[i][col] == num)
            return false;
    return true;
}

bool isSafe(int row, int col, int num)
{
    return (grid[row][col]==EMPTY && UsedInCol(col, num) && UsedInRow(row, num) && UsedInBox(row-row%3, col-col%3, num));
}

bool findEmpty(int &row, int &col)
{
    for(row=0; row<9; row++)
        for(col=0; col<9; col++)
            if(grid[row][col] == EMPTY)
                return true;
    return false;
}

bool solve()
{
    int row,col;
    if(!findEmpty(row, col))
        return true;
//    cout<<row<<" "<<col<<"\n";
    for(int i=1; i<=9; i++)
    {
        if(isSafe(row, col, i))
        {
            grid[row][col] = i;

            if(solve()) return true;

            grid[row][col] = EMPTY;            
        }
    }
    return false;
}

signed main()
{
    FastIO;
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                cin>>grid[i][j];
        
        if(solve())
        {
            for(int i=0; i<9; i++)
            {
                for(int j=0; j<9; j++)
                    cout<<grid[i][j]<<" ";
                cout<<"\n";
            }
        }
        else
            cout<<"-1";
        cout<<"\n";
    }
}