public class QuickSort {
	static private int partition(int[] arr, int l, int h) {
		int i=l,j=l, p=h;
		for(i=l; i<h; i++) {
			if(arr[i] <= arr[p]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				j+=1;
			}
		}
		
		int tmp = arr[h];
		arr[h] = arr[j];
		arr[j] = tmp;
				
		return j;		
	}
	static private void QuickSort(int[] arr, int l, int h) {
		if(l < h) {
			int p = partition(arr, l, h);
			QuickSort(arr, l, p-1);
			QuickSort(arr, p+1, h);
		}
	}
	
	static private void printArray(int[] arr) {
		for(int i=0; i<arr.length; i++)
			System.out.print(arr[i] + " ");
		System.out.println("\n");
	}
	
	public static void main(String[] args) {
		int[] arr = new int[10];
		for(int i=10; i>0; i--)
			arr[10-i] = i;
		printArray(arr);
		QuickSort(arr, 0, arr.length-1);
		printArray(arr);
	}
}