//https://codeforces.com/contest/1175/problem/B
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main()
{
    FastIO;
    int n,x,ans=1,sum=0;
    string ss;
    stack <int> s1;
    s1.push(1);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ss;
        if(ss=="for")
        {
            int t=1;
            if(s1.size()>1)
                t=s1.top();
            cin>>x;
            if(t*x>pow(2, 32)-1 || s1.top()==-1)
                s1.push(-1);
            else
                s1.push(t*x);
        }
        else if(ss=="add")
        {
            if(s1.top()==-1)
                ans=0;
            else
                sum+=s1.top();
            if(sum>pow(2, 32)-1)
                ans=0;
        }
        else if(ss=="end")
        {
            if(s1.size()==1)
                continue;
            s1.pop();
        }
    }
    
    //cout<<pow(2, 32)-1<<"\n";
    if(ans==1)
        cout<<sum;
    else
    cout<<"OVERFLOW!!!";
}