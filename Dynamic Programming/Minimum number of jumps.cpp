//https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0/?track=md-dp&batchId=144
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int solve(int a[], int n)
{
  //  if(a[0]==0)
  //      return -1;

    int step = 1;
    int maxReach = 0;
    int res = 0;
    for(int i=0; i<n-1; i++)
    {
        maxReach = max(maxReach, a[i]+i);
        step--;

        if(step == 0)
        {
            if(maxReach <= i)
                return -1;

            step = maxReach - i;
            res++;
        }
 //       cout<<step<<" ";
    }
    return res;
}

int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        int a[1000005];
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>a[i];

        cout<<solve(a, n)<<"\n";
    }
}