#include  <iostream> 
using namespace std; 
  
int shellSort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 
  
            int j;             
            for (j = i;j>= gap&&arr[j-gap]>temp;j-=gap) 
                arr[j] = arr[j - gap]; 
              
            arr[j]=temp; 
        } 
    } 
    return 0; 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0;i<n;i++) 
        cout<<arr[i] << " "; 
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
  
    shellSort(arr,n); 
  
    cout<<"\n\n\tArray after sorting : "; 
    printArray(arr,n); 
  
    return 0; 
} 
