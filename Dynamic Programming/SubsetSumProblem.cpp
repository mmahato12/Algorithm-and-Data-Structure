//https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool solve(int a[], int n, int sum)
{
    bool subset[n+1][sum+1];
    for (int i = 0; i <= n; i++) 
      subset[i][0] = true;
    for (int i = 1; i <= sum; i++) 
      subset[0][i] = false;
      
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j<a[i-1])
                subset[i][j]=subset[i-1][j];
            if(j>=a[i-1])
                subset[i][j]=subset[i-1][j] || subset[i-1][j-a[i-1]];
        }
    }
/*    for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }
  */  
    return subset[n][sum];
}

int main()
{
    FastIO;
    int T,n,a[1005];
    cin>>T;
    while(T--)
    {
        int sum=0,n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==0 && solve(a, n, sum/2)==true)
            cout<<"YES\n";
        else
        cout<<"NO\n";
        
    }
}