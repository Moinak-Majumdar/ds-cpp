#include<conio.h>
#include<iostream>
using namespace std;


void merge(int array[],int left,int mid,int right)
{
	int Sarr_1=mid-left+1;
	int Sarr_2=right-mid;

	// Create temp arrays
	int *L_arr=new int[Sarr_1];
	int *R_arr=new int[Sarr_2];

	// Copy data to temp arrays leftArray[] and rightArray[]
	
	for (int i=0;i<Sarr_1;i++)
		L_arr[i]=array[left+i];
		
	for (int j = 0;j<Sarr_2;j++)
		R_arr[j]=array[mid+1+j];

	int ind_Sarr_1=0, // Initial index of first sub-array
		ind_Sarr_2=0; // Initial index of second sub-array
	int ind_Marr=left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	
	while (ind_Sarr_1 < Sarr_1 && ind_Sarr_2 < Sarr_2) 
	{
		if (L_arr[ind_Sarr_1] <= R_arr[ind_Sarr_2]) 
		{
			array[ind_Marr] = L_arr[ind_Sarr_2];
			ind_Sarr_1++;
		}
		else {
			array[ind_Marr] = R_arr[ind_Sarr_2];
			ind_Sarr_2++;
		}
		ind_Marr++;
	}
	
	// Copy the remaining elements of left[], if there are any
		while (ind_Sarr_1 < Sarr_1) 
		{
			array[ind_Marr] = L_arr[ind_Sarr_1];
			ind_Sarr_1++;
			ind_Marr++;
		}
	
	// Copy the remaining elements of right[], if there are any
	
	while (ind_Sarr_2 < Sarr_2) 
	{
		array[ind_Marr] = R_arr[ind_Sarr_2];
		ind_Sarr_2++;
		ind_Marr++;
	}
}

// begin is for left index and end is right index of the sub-array of arr to be sorted
void mergeSort(int array[],int begin,int end)
{
	if (begin>=end)
		return; // Returns recursivly

	int mid = begin + (end - begin) / 2;
	mergeSort(array,begin,mid);
	mergeSort(array,mid+1,end);
	merge(array,begin,mid,end);
}

// Function to print an array
void printArray(int A[],int size)
{
	for (int i=0;i<size;i++)
		cout<<A[i]<<" ";
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

	mergeSort(arr,0,n-1);

	cout << "\n\nArray after sorting\n";
	printArray(arr,n);
	return 0;
}

