//https://codeforces.com/problemset/problem/339/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

vector <int> v;
string str;
bool ans;
int m;

void dfs(int cur, int prev, int index)
{

    if(index==m){
        cout<<"YES\n";
        for(auto &x: v)
            cout<<x<<" ";
        exit(0);
    }
    
    int cc=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='1' && prev!=i+1)
        {
            if(index%2)
                cc=cur-(i+1);
            else
                cc=cur+i+1;
                
            if(index==0)
            {
                v.push_back(i+1);
                dfs(cc, i+1, index+1);
            }
            else
            {
                if((cc>0 && cur<0) || (cc<0 && cur>0)){
                    v.push_back(i+1);
                    dfs(cc, i+1, index+1);
                }
            }
        }
    }
    if(v.size())
        v.pop_back();
}

int32_t main()
{
    FastIO;
    cin>>str>>m;
    dfs(0, 0, 0);
    cout<<"NO";
}