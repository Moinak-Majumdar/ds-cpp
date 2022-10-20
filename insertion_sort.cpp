#include<conio.h>
#include<iostream>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[],int n)
{
	int i,key,j;
	for (i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;

		while (j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

// A utility function to print an array of size n
void printArray(int arr[],int n)
{
	int i;
	for (i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

/* Driver code */
int main()
{
	cout<<"\tInsertion sort.....\n ";
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
    cout<<"\n\n\tArray before sorting : ";
    printArray(arr,n);
    
	insertionSort(arr,n);
	cout<<"\n\tSorted array: "; 
	printArray(arr,n);

	return 0;
}
