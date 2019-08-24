#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

void SelectionSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int loc = i;
        int lowest = arr[loc];
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < lowest)
            {
                lowest = arr[j];
                loc = j;
            }
        }

        swap(arr[i], arr[loc]);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

signed main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    SelectionSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
}