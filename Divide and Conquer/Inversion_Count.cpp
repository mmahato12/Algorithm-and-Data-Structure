//https://practice.geeksforgeeks.org/problems/inversion-of-array/0/?track=md-arrays&batchId=144

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int merge(int a[], int lo, int mid, int hi)
{
    int count=0;
    int n1 = mid-lo+1;
    int n2 = hi-mid;

    vector <int> v1,v2;
    for(int i=0; i<n1; i++)
        v1.push_back(a[lo+i]);
    for(int i=0; i<n2; i++)
        v2.push_back(a[mid+i+1]);

    v1.push_back(INT_MAX);
    v2.push_back(INT_MAX);

    int i=0,j=0,k=0;
    while(k < n1+n2)
    {
        if(v1[i] < v2[j])
        {
            a[lo+k] = v1[i];
            ++k;
            ++i;
        }
        else if(v1[i] > v2[j])
        {
            a[lo+k] = v2[j];
            count += n1 - i;
            ++k;
            ++j;   
        }
        else
        {
            if(i < n1)
            {
                a[lo+k] = v1[i];
                ++k;
                ++i;
            }
            else
            {
                a[lo+k] = v2[j];
                ++k;
                ++j;
            }
        }
    }

    return count;
}

int mergeSort(int a[], int lo, int hi)
{
    int cnt=0;
    if(lo < hi)
    {
        int mid = (lo + hi) / 2;

        cnt = mergeSort(a, lo, mid);
        cnt += mergeSort(a, mid+1, hi);

        cnt += merge(a, lo, mid, hi);
    }

    return cnt;
}

signed main()
{
    FastIO;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a[n+5];
        for(int i=0; i<n; i++)
            cin>>a[i];

        int ans = mergeSort(a, 0, n-1);
        
/*        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
*/
        cout<<ans<<"\n";
    }
}