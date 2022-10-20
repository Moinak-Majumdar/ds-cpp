#include <iostream>
using namespace std;

// Merges two subarrays of array[]. First subarray is arr[begin..mid].Second subarray is arr[mid+1..end]
void merge(int array[], int left, int mid, int right)
{
	int subArrayOne = mid - left + 1;
	int subArrayTwo = right - mid;


	int *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];


	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	/* Copy the remaining elements of right[], if there are any */
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

/* begin is for left index and end is right index of the sub-array of arr to be sorted */
void mergeSort(int array[], int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	cout<<"\tMerge sort.....\n ";
    int n,k=0;
	cout<<"\n\tEnter number of to short : ";
	cin>>n;
    int arr[n];
	while(k<n)
	{
		cout<<"\n\t\tEnter element arr["<<k<<"] : ";
		cin>>arr[k];	
		k++;
	}
	cout<<"\narray before sorting \n";
	printArray(arr,n);

	mergeSort(arr, 0,n-1);

	cout << "\nSorted array is \n";
	printArray(arr,n);
	return 0;
}

