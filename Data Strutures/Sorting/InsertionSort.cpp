#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

insertionSort(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && temp<arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
//        cout<<i<<" "<<j<<"\n";
        arr[j+1] = temp;
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
	insertionSort(arr, 6);
	printArray(arr, 6);
}