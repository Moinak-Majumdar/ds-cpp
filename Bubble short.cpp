#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i,j;  
    for (i=0;i<n-1;i++)      
      
    // Last i elements are already in place  
    for (j=0;j<n-i-1;j++)  
        if (arr[j]>arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  

int main()  
{ 
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
    cout<<"\n\tArray before sorting : "; 
    printArray(arr,n); 
    bubbleSort(arr,n);  
    cout<<"\n\tSorted array: ";  
    printArray(arr,n);  
    return 0;  
}  
