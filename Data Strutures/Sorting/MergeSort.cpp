#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

void merge(int arr[], int low, int mid, int high)
{
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1+1],R[n2+1];

    for(int i=0; i<n1; i++)
        L[i] = arr[low+i];
    for(int i=0; i<n2; i++)
        R[i] = arr[mid+i+1];

    i=0, j=0, k=low;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }
    
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

int print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

signed main()
{
    FastIO;
    int arr[10]={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    print(arr, 10);

    mergeSort(arr, 0, 9);
    
    print(arr, 10);
    
}