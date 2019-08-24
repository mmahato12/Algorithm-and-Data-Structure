#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for(int j=low; j<high; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
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

    quickSort(arr, 0, 9);
    
    print(arr, 10);
    
}