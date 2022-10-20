#include<iostream> 
using namespace std; 

// Return minimum index 
int minIndex(int a[],int i,int j) 
{ 
    if (i==j) 
        return i; 
  	int k=minIndex(a,i+1,j); 
    return (a[i]<a[k]) ? i:k; 
} 
  

void recurSelectionSort(int a[], int n, int index = 0) 
{ 
     
    if (index==n) // Return when starting and size are same
       return; 
  
    int k=minIndex(a,index,n-1); 
  
    
    if (k != index)  // Swapping when index nd minimum index are not same 
       swap(a[k], a[index]); 
  
    // Recursion
    recurSelectionSort(a,n,index + 1); 
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
	cout<<"\tSelection sort.....\n ";
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

    recurSelectionSort(arr, n); 
  	cout<<"\n\tSorted array: ";  
    printArray(arr,n);  

} 
