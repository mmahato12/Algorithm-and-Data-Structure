//https://codeforces.com/contest/1073/problem/C
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
int n,x,y;
int dpX[200005],dpY[200005];

bool check(int m)
{
//    cout<<n<<"\n";
    for(int i=1; i+m-1<=n; i++)
    {
        int newX = dpX[n] - dpX[i+m-1] + dpX[i-1];
        int newY = dpY[n] - dpY[i+m-1] + dpY[i-1];

        int diff=abs(newX-x)+abs(newY-y);

//        cout<<"i: "<<i<<" "<<newX<<" "<<newY<<" "<<diff<<" "<<(diff-m)%2<<endl;
        if(diff<=m && (diff-m)%2==0)
            return true;
    }
    return false;
}

int32_t main()
{
    string s;
    cin>>n>>s;
    cin>>x>>y;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='U')
            dpY[i+1]+=1;
        else if(s[i]=='D')
            dpY[i+1]-=1;
        else if(s[i]=='R')
            dpX[i+1]+=1;
        else
            dpX[i+1]-=1;
        dpX[i+1]+=dpX[i];
        dpY[i+1]+=dpY[i];
    }

/*    for(int i=0; i<=n; i++)
        cout<<dpX[i]<<" ";
    cout<<"\n";
    for(int i=0; i<=n; i++)
        cout<<dpY[i]<<" ";
*/    int left=-1,right=n,ans=-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
//        cout<<mid<<"\n";
        if(check(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
      cout<<ans;
}    