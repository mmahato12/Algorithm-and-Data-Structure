//https://practice.geeksforgeeks.org/problems/combination-sum-part-2/0/?track=md-recursion&batchId=144

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
vector <int> v;
vector <vector <int> > vv;

void SUM(int a[], int i, int sum)
{
    if(sum < 0)
        return;
//    cout<<i<<": ";
    if(sum == 0)
    {
        vv.push_back(v);
        return;
    }
    if(i>=n)
        return;
    v.push_back(a[i]);
    SUM(a, i+1, sum - a[i]);
    v.pop_back();
    
    while(i<n-1 && a[i] == a[i+1]) i++;
    SUM(a, i+1, sum);
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	    v.clear();
	    vv.clear();
	    cin>>n;
	    int a[n+5],sum;
	    for(int i=0; i<n; i++)
	        cin>>a[i];
	    cin>>sum;
	    sort(a, a+n);
	   // cout<<n<<" "<<sum<<"-\n";
	   SUM(a, 0, sum);
	   for(int i=0; i<vv.size(); i++)
	   {
	       cout<<"(";
	       for(int j=0;j<vv[i].size();j++)
	       {    
	           if(j!=vv[i].size()-1)
	            cout<<vv[i][j]<<" ";
	            else 
	             cout<<vv[i][j];
	         }
            cout<<")";
	   }
	   if(vv.size()==0)
	       cout<<"Empty";
	   cout<<"\n";
	}
}