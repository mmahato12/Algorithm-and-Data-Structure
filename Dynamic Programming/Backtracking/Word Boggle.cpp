using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

char board[15][15];
bool mark[15][15];
string s[15];
set <string> vv;
bool ok;
int n,m;

bool isSafe(int id, int col, int i, int j)
{
    if(mark[i][j]==0 && s[id][col] == board[i][j])
        return true;

    return false;
}

void solve(int id, int col)
{
    if(col >= s[id].size())
    {
        vv.insert(s[id]);
        ok = false;
        return;
    }
    
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
        if(isSafe(id, col, i, j) && ok)
        {
            mark[i][j] = 1;

            solve(id, col+1);

            mark[i][j] = 0;
        }
    }
}

signed main()
{
    FastIO;
    int T,p;
    cin>>T;
    while(T--)
    {
        vv.clear();
        cin>>p;
        for(int i=0; i<p; i++)
            cin>>s[i];

        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mark[i][j] = 0;
                cin>>board[i][j];
            }
        }
        for(int i=0; i<p; i++)
        {
            ok = true;
            solve(i, 0);
//            cout<<s[i]<<" "<<vv.size()<<"\n";
        }
        
        if(vv.size())
        {
            for(auto &x: vv)
                cout<<x<<" ";
            cout<<"\n";
        }
        else
            cout<<"-1\n";
    }
}